#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dir[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
int visited[101][101];
int n, m;

bool isinside(int x, int y){
    if(x >= 0 && y >= 0 && x < n && y < m){
        return true;
    }
    return false;
}

bool bfs(int a, int b, vector<vector<int>> farm){
    queue<pair<int,int>> q;
    q.push(make_pair(a,b));
    visited[a][b] = 1;

    int x, y, h;
    
    pair<int,int> data;
    while(!q.empty()){
        data = q.front(); q.pop();
        h = farm[data.first][data.second];

        for(int i=0; i<8; i++){
            x = data.first + dir[i][0];
            y = data.second + dir[i][1];

            if(isinside(x,y) && !visited[x][y]){
                if(farm[x][y] <= h){
                    q.push(make_pair(x,y));
                    visited[x][y] = 1;
                }
            }
        }
    }
    return true;
}

int main(){
    cin >> n >> m;
    
    vector<vector<int>> farm;
    vector<int> temp;

    int data;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> data;
            temp.push_back(data);
        }
        farm.push_back(temp);
        temp.clear();
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(farm[i][j]  &&  bfs(i, j, farm)){
                cout << i << " " << j << "\n";
                ans++;
            }
        }
    }
    cout << ans;
}