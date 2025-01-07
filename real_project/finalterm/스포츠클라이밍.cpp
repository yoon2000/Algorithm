#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<char>> map;
int is_hold[501][501];
int is_space[501][501];
int is_hurdle[501][501];
int visited[501][501];
int dis[501][501];

int dir[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
int dir_jump[4][2] = {{0,-2}, {0,2}, {0,-3}, {0,3}};

void bfs(int start_x, int start_y, int n);
bool is_inside(int x, int y, int n){
    return (x >= 0 && y >= 0 && x < n && y < n);
}

// inside 범위 체크 해야하나?
bool check_jump(pair<int,int> a, pair<int,int> b){
    // 좌로 점프
    if(a.first - 1 < 0) return false; 

    if(a.second > b.second){
        for(int i=b.second; i <= a.second; i++){
            if(!is_space[b.first-1][i]) return false;
        }
        for(int i=b.second+1; i<a.second; i++){
            if(!is_space[b.first][i]) return false;
        }
        return true;
    }
    // 우로 점프
    else{
        for(int i=a.second; i <= b.second; i++){
            if(!is_space[b.first-1][i]) return false;
        }
        for(int i=a.second+1; i<b.second; i++){
            if(!is_space[b.first][i]) return false;
        }
        return true;
    }
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        char data;
        vector<char> temp;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                is_hold[i][j] = 0;
                is_space[i][j] = 0;
                is_hurdle[i][j] = 0;
                visited[i][j] = 0;
                dis[i][j] = 0;

                cin >> data;
                temp.push_back(data);
                if(data == 'H') is_hold[i][j] = 1;
                else if(data == '.') is_space[i][j] = 1;
                else if(data == 'X') is_hurdle[i][j] = 1;
            }
            map.push_back(temp);
            temp.clear();
        }

        bfs(n-1, 0, n);

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(map[i][j] == 'H'){
                    if(dis[i][j]){
                        cout << dis[i][j] << " ";
                    }
                    else{
                        cout << -1 << " ";
                    }
                }

                else{
                    cout << 0 << " ";
                }
            }
            cout << endl;
        }
        map.clear();

    }
}

void bfs(int start_x, int start_y, int n){
    visited[start_x][start_y] = 1;
    dis[start_x][start_y] = 1;
    pair<int,int> point = make_pair(start_x, start_y);
    queue<pair<int,int>> q;
    q.push(point);

    int x,y;
    while(!q.empty()){
        point = q.front(); q.pop();

        // 상하좌우 확인
        for(int i=0; i<4; i++){
            x = point.first + dir[i][0];
            y = point.second + dir[i][1];
            if(!visited[x][y] && is_hold[x][y] && is_inside(x,y,n)){
                visited[x][y] = 1;
                dis[x][y] = dis[point.first][point.second] + 1;
                q.push(make_pair(x, y));
            }
        }

        // 2, 3칸 점프하기
        for(int i=0; i<4; i++){
            x = point.first + dir_jump[i][0];
            y = point.second + dir_jump[i][1];
            if(!visited[x][y] && is_hold[x][y] && is_inside(x,y,n)
            && check_jump(point, make_pair(x,y))){
                visited[x][y] = 1;
                dis[x][y] = dis[point.first][point.second] + 1;
                q.push(make_pair(x,y));
            }
        }

        // 위로 2칸 점프하기
        x = point.first - 2;
        y = point.second;
        if(!visited[x][y] && is_hold[x][y] && is_inside(x,y,n)
        && is_space[x+1][y]){
            visited[x][y] = 1;
            dis[x][y] = dis[point.first][point.second] + 1;
            q.push(make_pair(x,y));
        }

        // 좌상단 탐색
        x = point.first - 1;
        y = point.second - 1;
        if(!visited[x][y] && is_hold[x][y] && is_inside(x,y,n)
        && is_space[x][y+1] && is_space[x+1][y]){
            visited[x][y] = 1;
            dis[x][y] = dis[point.first][point.second] + 1;
            q.push(make_pair(x,y));
        }

        // 우상단 탐색
        x = point.first - 1;
        y = point.second + 1;
        if(!visited[x][y] && is_hold[x][y] && is_inside(x,y,n)
        && is_space[x][y-1] && is_space[x+1][y]){
            visited[x][y] = 1;
            dis[x][y] = dis[point.first][point.second] + 1;
            q.push(make_pair(x,y));
        }
    }
}