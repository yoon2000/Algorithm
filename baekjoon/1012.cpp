#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int m, n, k;
int dir[4][2] = {{-1,0}, {0,-1}, {0,1}, {1,0}};

bool is_in(int x, int y){
    if(x >= 0 && y >= 0 && x < m && y < n){
        return true;
    }
    return false;
}

int main(){
    int t;
    cin >> t;

    vector<int> answer;

    while(t--){
        int ret = 0;
        cin >> m >> n >> k;

        vector<vector<int>> map(m, vector<int>(n, 0));
        vector<vector<int>> visited(m, vector<int>(n, 0));

        int x, y;
        for(int i=0; i<k; i++){
            cin >> x >> y;
            map[x][y] = 1;
        }

        // bfs 돌아가기
        int nx, ny;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(map[i][j] && !visited[i][j]){
                    // cout << "i = " << i << ", j = " << j << endl;
                    ret++;
                    visited[i][j] = 1;
                    queue<pair<int,int>> q;
                    q.push(make_pair(i,j));

                    pair<int,int> data;
                    while(!q.empty()){
                        data = q.front(); q.pop();
                        x = data.first;
                        y = data.second;

                        // cout << "x = " << x << ", y = " << y << endl;

                        for(int p=0; p<4; p++){
                            nx = x + dir[p][0];
                            ny = y + dir[p][1];

                            if(is_in(nx, ny) && map[nx][ny] 
                            && !visited[nx][ny]){
                                visited[nx][ny] = 1;
                                q.push(make_pair(nx,ny));
                            }
                        }
                    }
                }
            }
        }
        answer.push_back(ret);
    }
    for(auto i : answer){
        cout << i << endl;
    }
}