#include <iostream>
#include <vector>
#include <queue>
#define INF 100001
using namespace std;

vector<pair<int,int>> dijkstra(int start, vector<vector<pair<int,int>>> graph, int n){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push(make_pair(0, start));
    vector<int> d(n+1, INF);
    vector<pair<int,int>> path(n+1);
    d[start] = 0;

    while(!pq.empty()){
        int curr_node = pq.top().second;
        int curr_weight = pq.top().first;
        pq.pop();

        if(d[curr_node] > curr_weight){
            for(auto next : graph[curr_node]){
                int next_node = next.second;
                int next_weight = next.first;

                if(d[next_node] > curr_weight + next_weight){
                    d[next_node] = curr_weight + next_weight;
                    pq.push(make_pair(d[next_node], next_node));
                    path[next_node] = make_pair(next_weight, curr_node);
                }
            }
        }
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
        for(int i=1; i<n+1; i++){
            cin >> k >> m;
            for(int j=0; j<m; j++){
                cin >> node_num >> weight;
                graph[k].push_back(make_pair(weight, node_num));
            }
        }

        vector<pair<int,int>> path = dijkstra(1, graph, n);

        int sum = 0;
        for(int i=1; i<n+1; i++){
            sum += path[i].first;
        }
        cout << sum << endl;
    }
}