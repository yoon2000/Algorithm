#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, v;

void dfs(vector<vector<int>> graph, vector<int> visited){
    stack<int> st;
    st.push(v);
    
    int data;
    while(!st.empty()){
        data = st.top(); st.pop();
        if(!visited[data]){
            visited[data] = 1;
            cout << data << " ";
            for(int i=graph[data].size()-1; i>=0; i--){
                st.push(graph[data][i]);
            }
        }
    }
    cout << "\n";
}

void bfs(vector<vector<int>> graph, vector<int> visited){
    queue<int> q;
    q.push(v);

    int data;
    while(!q.empty()){
        data = q.front(); q.pop();
        if(!visited[data]){
            visited[data] = 1;
            cout << data << " ";
            for(auto i : graph[data]){
                q.push(i);
            }
        }
    }
    cout << "\n";
}

int main(){
    cin >> n >> m >> v;

    vector<vector<int>> graph(n+1);
    vector<int> visited(n+1, 0);

    int a, b;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i=0; i<n+1; i++){
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(graph, visited);
    bfs(graph, visited);
}