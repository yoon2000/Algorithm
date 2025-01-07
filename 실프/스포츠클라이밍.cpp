/*
1. 상하좌우 인접한 지역에 홀드가 있는 경우 주변 지형과 상관없이 이동 가능.
 2. 다음 조건을 만족하는 경우 좌우로 2칸 또는 3칸 떨어진 홀드로 이동 가능.
 - 두 홀드의 바로 윗 칸이 빈칸일 때
 - 두 홀드를 직선으로 이었을 때 지나가는 칸들이 빈칸일 때
 - 두 홀드를 직선으로 이었을 때 지나가는 칸들의 윗 칸이 비었을 때
 3. 바로 윗 칸이 빈칸인 경우 위로 2칸 떨어진 홀드로 이동 가능.
 4. 왼쪽 칸과 윗 칸이 빈칸인 경우 좌상단에 있는 홀드로 이동 가능.
 5. 오른쪽 칸과 윗 칸이 빈칸인 경우 우상단에 있는 홀드로 이동 가능.

 이동 가능 방향
 1. 상하좌우 1칸 / 조건 x

 2. 좌우로 2,3칸 / 조건 윗부분 사잇길 다 빈칸

 3. 위로 2칸 / 조건 윗 한칸이 빈칸

 4. 좌상단 1칸 / 조건 왼쪽과 위칸이 빈칸
 5. 우상단 1칸 / 조건 오른쪽과 위칸이 빈칸

2
3
H . H
. H X
H . H
6
H . . . . H
. . H . . .
. . H . X H
H . . H . .
. . . . H H
H . . H . H
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dir[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
int dir_jump[4][2] = {{0, -2}, {0, 2}, {0, -3}, {0,3}};

int visited[501][501];
int dis[501][501];
int is_hold[501][501];
int is_space[501][501];
int is_hurdle[501][501];

vector<vector<char>> map;

bool check_jump(pair<int,int> a, pair<int,int> b){
    // 좌로 점프
    if(a.second > b.second){
        // 사이 탐색
        for(int i= b.second + 1; i<a.second; i++){
            if(!is_space[a.first][i]){
                return false;
            }
        }
        // 윗공간 탐색
        for(int i=b.second; i<a.second+1; i++){
            if(!is_space[a.first-1][i]){
                return false;
            }
        }
        return true;
    }
    // 우로 점프
    else{
        // 사이 탐색
        for(int i=a.second + 1; i<b.second; i++){
            if(!is_space[a.first][i]){
                return false;
            }
        }
        // 윗공간 탐색
        for(int i=a.second; i<b.second+1; i++){
            if(!is_space[a.first-1][i]){
                return false;
            }
        }
        return true;
    }
}

void bfs(int start_x, int start_y, int n){

    queue<pair<int,int>> q;
    visited[start_x][start_y] = 1;
    dis[start_x][start_y] = 1;
    pair<int,int> point(start_x, start_y);
    q.push(point);

    int x, y;
    while(!q.empty()){
        point = q.front(); q.pop();

        // 상하좌우 탐색
        for(int i=0; i<4; i++){
            x = point.first + dir[i][0];
            y = point.second + dir[i][1];

            if(x >= 0 && x < n && y >= 0 && y < n
            && !visited[x][y] && is_hold[x][y]){
                visited[x][y] = 1;
                dis[x][y] = dis[point.first][point.second] + 1;
                q.push(make_pair(x,y));
            }
        }

        // 좌, 우 2,3칸 점프 탐색
        for(int i=0; i<4; i++){
            x = point.first + dir_jump[i][0];
            y = point.second + dir_jump[i][1];

            if(x >= 0 && x < n && y >= 0 && y < n
            && !visited[x][y] && is_hold[x][y]
            && check_jump(point, make_pair(x,y))){
                visited[x][y] = 1;
                dis[x][y] = dis[point.first][point.second] + 1;
                q.push(make_pair(x,y));
            }
        }

        // 위로 2칸 점프
        x = point.first - 2; y = point.second;
        if(x >= 0 && x < n && y >= 0 && y < n
        && !visited[x][y] && is_hold[x][y] && is_space[x+1][y]){
            visited[x][y] = 1;
            dis[x][y] = dis[point.first][point.second] + 1;
            q.push(make_pair(x,y));
        }

        // 좌상단 이동
        x = point.first - 1; y = point.second -1;
        if(x >= 0 && x < n && y >= 0 && y < n
        && !visited[x][y] && is_hold[x][y]
        && is_space[x][y+1] && is_space[x+1][y]){
            visited[x][y] = 1;
            dis[x][y] = dis[point.first][point.second] + 1;
            q.push(make_pair(x,y));
        }
        // 우상단 이동
        x = point.first - 1; y = point.second + 1;
        if(x >= 0 && x < n && y >= 0 && y < n
        && !visited[x][y] && is_hold[x][y]
        && is_space[x][y-1] && is_space[x+1][y]){
            visited[x][y] = 1;
            dis[x][y] = dis[point.first][point.second] + 1;
            q.push(make_pair(x,y));
        }
    }

}

int main(){
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;

        vector<char> temp;
        char data;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin >> data;

                visited[i][j] = 0;
                dis[i][j] = 0;
                is_hold[i][j] = 0;
                is_space[i][j] = 0;
                is_hurdle[i][j] = 0;

                if(data == 'H') is_hold[i][j] = 1;
                if(data == '.') is_space[i][j] = 1;
                if(data == 'X') is_hurdle[i][j] = 1;

                temp.push_back(data);
            }
            map.push_back(temp);
            temp.clear();
        }

        bfs(n-1, 0, n);

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(map[i][j] == 'H'){
                    if(visited[i][j]){
                        cout << dis[i][j] << " ";
                    }
                    else{
                        cout << -1 << " ";
                    }
                }
                else if(map[i][j] == '.' || map[i][j] == 'X'){
                    cout << 0 << " ";
                }
            }
            cout << endl;
        }

        map.clear();

    }
}