#include <iostream>
#include <queue>
#include <vector>
#include <set>
using namespace std;

struct edge{
    int first;
    int second;
    int weight;

    edge(int a, int b, int c){
        first = a;
        second = b;
        weight = c;
    }
};

struct cmp{
    bool operator()(pair<int,int> a, pair<int,int> b){
        return a.second > b.second;
    }
};

void prim(vector<vector<pair<int,int>>> graph, int n){
    set<int> s;
    s.insert(1);
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
    for(auto i : graph[1]){
        pq.push(make_pair(i.first, i.second));
    }    

    int sumOfWeight = 0;
    while(s.size() < n){
        pair<int,int> data = pq.top(); pq.pop();
        if(!s.count(data.first)){
            s.insert(data.first);
            sumOfWeight += data.second;

            for(auto i : graph[data.first]){
                pq.push(make_pair(i.first, i.second));
            }
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

        for(int i=0; i<n; i++){
            cin >> k >> m;
            for(int j=0; j<m; j++){
                cin >> node_num >> weight;
                graph[k].push_back(make_pair(node_num, weight));
                graph[node_num].push_back(make_pair(k, weight));
            }
        }

        prim(graph, n);
    }
}