#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <limits.h>
using namespace std;

void prim(int start, vector<vector<pair<int,int>>> graph, int n){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    set<int> s;
    pq.push(make_pair(0, start));

    int sumOfWeight = 0;

    while(s.size() < n){
        int curr_node = pq.top().second;
        int curr_weight = pq.top().first;
        pq.pop();

        if(s.count(curr_node)) continue;

        s.insert(curr_node);
        sumOfWeight += curr_weight;

        for(auto next : graph[curr_node]){
            int next_node = next.second;
            int next_weight = next.first;
            pq.push(make_pair(next_weight, next_node));
        }
    }

    cout << sumOfWeight << endl;
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

        prim(1, graph, n);
    }
}