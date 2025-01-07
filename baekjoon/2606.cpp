#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

int n, m;

vector<vector<int>> v(101);
int visited[101];

void bfs(){
    int data, ans = 0;

    queue<int> q; q.push(1);
    visited[1] = 1;

    while(!q.empty()){
        data = q.front(); q.pop();

        // 이웃 컴퓨터들 큐에 넣어주기
        for(auto i : v[data]){
            if(!visited[i]){
                q.push(i);
                visited[i] = 1;
                ans++;
            }
        }
    }
    cout << ans;
}

int main(){
    cin >> n >> m;

    int a, b;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    bfs();

}