#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

struct cmp{
    bool operator()(pair<int,int> a, pair<int,int> b){
        // < 가 오름차순인데 pq는 반대
        return a.second > b.second;
    }
};

int dijkstra(int node_num, vector<vector<pair<int,int>>> graph, int start, int end){
    // visited 체크, 거리 INF로 나타내는 배열 필요?, pq 확인하면서 최소 거리 노드 방문 + 추가

    vector<int> visited(node_num + 1, 0);
    vector<int> dist(node_num + 1, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;

    pair<int,int> data = make_pair(start, 0);
    pq.push(data);

    while(!pq.empty()){
        data = pq.top(); pq.pop();

        if(visited[data.first]) continue;
        
        visited[data.first] = 1;

        if(data.first == end) break;

        for(auto near : graph[data.first]){
            if(!visited[near.first] && dist[near.first] > data.second + near.second){
                dist[near.first] = data.second + near.second;
                pq.push(make_pair(near.first, dist[near.first]));
            }
        }
        
    }

    return dist[end];
}

int main(){

    int node_num, connection_num, start, end;

    cin >> node_num >> connection_num >> start >> end;

    vector<vector<pair<int,int>>> graph(node_num + 1);

    for(int i=0; i < connection_num; i++){
        int a,b,c;
        
        cin >> a >> b >> c;

        // pair의 second값이 가중치
        graph[a].push_back(make_pair(b,c));
        graph[b].push_back(make_pair(a,c));
    }

    int answer = dijkstra(node_num, graph, start, end);

    cout << answer << endl;

}