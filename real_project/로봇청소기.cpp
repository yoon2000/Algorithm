#include <iostream>
#include <vector>
using namespace std;

int n, dir;

int visited[51][51];
int check[51][51];

bool ininside(int x, int y){
    return (x >= 0 && y>=0 && x < n && y < n);
}

void turn_left(){
    if(dir == 0){ //북쪽
        dir = 3;
    }
    else if(dir == 1){ //동쪽
        dir = 0;
    }
    else if(dir == 2){ //남쪽
        dir = 1;
    }
    else{ //서쪽
        dir = 2;
    }
}

pair<int,int> left_point(int x, int y){
    if(dir == 0){ //북쪽
        y--;
    }
    else if(dir == 1){ //동쪽
        x--;
    }
    else if(dir == 2){ //남쪽
        y++;
    }
    else{ //서쪽
        x++;
    }
    return make_pair(x,y);
}

pair<int,int> back_point(int x, int y){
    if(dir == 0){ //북쪽
        x++;
    }
    else if(dir == 1){ //동쪽
        y--;
    }
    else if(dir == 2){ //남쪽
        x--;
    }
    else{ //서쪽
        y++;
    }
    return make_pair(x,y);
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int x, y, data;
        cin >> n >> dir;
        cin >> x >> y;

        vector<vector<int>> map;
        vector<int> temp;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin >> data;
                temp.push_back(data);

                visited[i][j] = 0;
                check[i][j] = 0;
            }
            map.push_back(temp);
            temp.clear();
        }

        pair<int,int> point = make_pair(x, y);
        pair<int,int> left_p;
        pair<int,int> back_p;
        
        int nx,ny;
        int clean_cnt = 0;
        int turn_cnt = 0;

        // 시작 위치 체크
        if(!map[x][y]) clean_cnt++;
        visited[x][y] = 1;
        check[x][y] = 1; 

        // while문 종료를 어떻게 해야할까..?
        while(1){
            // 현재 좌표
            x = point.first;
            y = point.second;

            // 현재 좌표기준 왼쪽 좌표
            left_p = left_point(x, y);
            nx = left_p.first;
            ny = left_p.second;

            // method 2-1
            if(ininside(nx,ny) && !map[nx][ny] && !visited[nx][ny]){
                turn_left();
                visited[nx][ny] = 1;
                check[nx][ny] = 1;
                point = make_pair(nx,ny);

                clean_cnt++;
                turn_cnt = 0;
            }

            // method 2-3, 2-4 즉 방향 4군데가 다 청소할수 없을경우
            else if(turn_cnt == 4){

                // 후진 좌표
                back_p = back_point(x, y);
                nx = back_p.first;
                ny = back_p.second;

                // 후진좌표가 범위를 넘거나 벽일 경우 2-4하면서 종료, while break!
                if(!ininside(nx,ny) || map[nx][ny]){
                    break;
                }
                // 후진 가능 경우 method 2-3실행
                else{
                    point = make_pair(nx,ny);
                    turn_cnt = 0;
                }
            }

            // method 2-2
            else{
                turn_left();
                turn_cnt++;
            }
        }

        cout << clean_cnt << endl;

    }
}