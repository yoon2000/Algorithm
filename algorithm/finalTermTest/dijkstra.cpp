#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#define MAX_NUM 1001
using namespace std;

int dis[MAX_NUM];

struct cmp{
    bool operator()(pair<int,int> a, pair<int,int> b){
        return a.second > b.second;
    }
};

vector<pair<int,int>> dijkstra(int start, vector<vector<pair<int,int>>> graph, int n){
    vector<pair<int,int>> path(n+1);
    vector<int> visited(n+1, 0);

    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
    pq.push(make_pair(start, 0));
    dis[start] = 0;

    while(!pq.empty()){
        int curr_node = pq.top().first;
        int curr_weight = pq.top().second;
        pq.pop();

        if(!visited[curr_node]){
            for(auto next : graph[curr_node]){
                int next_node = next.first;
                int next_weight = next.second;

                if(dis[next_node] >= curr_weight + next_weight){
                    dis[next_node] = curr_weight + next_weight;
                    pq.push(make_pair(next_node, dis[next_node]));
                    path[next_node] = make_pair(curr_node, next_weight);
                }
            }   
        }

        visited[curr_node] = 1;
    }

    return path;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int n, k, m, node_num, weight;
        cin >> n;

        vector<vector<pair<int,int>>> graph(n+1);

        for(int i=1; i<=n; i++){
            dis[i] = INT_MAX; //INF 설정 및 초기화

            cin >> k >> m;
            for(int j=0; j<m; j++){
                cin >> node_num >> weight;
                graph[k].push_back(make_pair(node_num, weight));
            }
        }

        vector<pair<int,int>> path = dijkstra(1, graph, n);

        int sum = 0;
        for(auto i : path){
            sum += i.second;
        }

        cout << sum << endl;
    }
}