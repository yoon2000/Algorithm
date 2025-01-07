#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>
using namespace std;

vector<int> d(20001, INT_MAX);
vector<vector<pair<int,int>>> graph(20001);

struct cmp{
    bool operator()(pair<int,int> a, pair<int,int> b){
        return a.second > b.second;
    }
};

void dijkstra(int start, int vertics_num){
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
    pq.push(make_pair(start, 0));
    d[start] = 0;

    while(!pq.empty()){
        int curr_node = pq.top().first;
        int curr_weight = pq.top().second;
        pq.pop();

        if(curr_weight <= d[curr_node]){
            for(auto neighbor : graph[curr_node]){
                int next_node = neighbor.first;
                int next_weight = neighbor.second;

                if(d[next_node] > d[curr_node] + next_weight){
                    d[next_node] = d[curr_node] + next_weight;
                    pq.push(make_pair(next_node, d[next_node]));
                }
            }
        }
    }

    // print 하기
    for(int i=1; i<=vertics_num; i++){
        if(d[i] == INT_MAX){
            cout << "INF" << endl;
        }
        else{
            cout << d[i] << endl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int v, e, start, node1, node2, weight;
    cin >> v >> e;
    cin >> start;

    for(int i=0; i<e; i++){
        cin >> node1 >> node2 >> weight;
        graph[node1].push_back(make_pair(node2, weight));
    }

    dijkstra(start, v);
}