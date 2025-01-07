#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_INT 1001

int dfs(vector<vector<int>> v, int n);
vector<int> visited(MAX_INT, 0);

int main(){
    int t;
    cin >> t;

    while(t--){
        int n, k, m, data;
        cin >> n;

        vector<vector<int>> v(n+1);
        for(int i=0; i<n; i++){
            visited[i] = 0;
            cin >> k >> m;
            for(int j=0; j<m; j++){
                cin >> data;
                v[k].push_back(data);
            }
        }
        visited[n] = 0;

        vector<int> answer;
        for(int start=1; start<n+1; start++){
            int ret = dfs(v, start);
            if(ret){
                answer.push_back(ret);
            }
        }

        cout << answer.size();
        sort(answer.begin(), answer.end());
        for(auto i : answer){
            cout << " " <<  i;
        }
        cout << endl;
    }
}

int dfs(vector<vector<int>> graph, int start){
    if(visited[start]){ // 이미 방문한 노드일 경우
        return 0;
    }

    queue<int> q;
    q.push(start);
    visited[start] = 1;
    int cmp_sz = 1;

    while(!q.empty()){
        int data = q.front();
        q.pop();

        for(auto i : graph[data]){
            if(!visited[i]){
                visited[i] = 1;
                q.push(i);
                cmp_sz++;
            }
        }
    }

    return cmp_sz;
}