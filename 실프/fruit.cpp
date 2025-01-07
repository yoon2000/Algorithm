#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dir[4][2] = {{0,-1}, {0,1}, {1,0}, {-1,0}};
vector<vector<int>> box;
vector<vector<int>> box_2;
int visited[501][501];
int n, m;

bool check_box();
void pass_one_day();
void bfs(int x, int y);

int main(){
    int t;
    cin >> t;

    while(t--){
        cin >> n >> m;
        int data;

        vector<int> temp;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                visited[i][j] = 0;
                cin >> data;
                temp.push_back(data);
            }
            box.push_back(temp);
            box_2.push_back(temp);
            temp.clear();
        }

        // 익지 못하는 사과 존재할 경우 찾기
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(box[i][j] == 1){
                    bfs(i, j);
                }
            }
        }

        bool alone = false;
        for(auto i : box_2){
            for(auto j : i){
                if(j == 0) alone = true;
            }
        }

        if(alone) cout << -1 << endl;
        else{
            int day = 0;
            while(!check_box()){
                pass_one_day();
                day++;
            }
            cout << day << endl;
        }

        box.clear();
        box_2.clear();
    }
}
bool check_box(){
    for(auto i : box){
        for(auto j : i){
            if(j == 0){
                return false;
            }
        }
    }
    return true;
}
void pass_one_day(){
    int x,y;
    vector<pair<int,int>> v;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(box[i][j] == 1){
                for(int k=0; k<4; k++){
                    x = i + dir[k][0];
                    y = j + dir[k][1];
                    if(x >= 0 && x < n && y >= 0 && y < m
                    && box[x][y] == 0){
                        v.push_back(make_pair(x,y));
                    }
                }
            }
        }
    }
    for(auto i : v){
        box[i.first][i.second] = 1;
    }
}
void bfs(int x, int y){
    pair<int,int> point(x,y);
    visited[x][y] = 1;
    queue<pair<int,int>> q;
    q.push(point);

    while(!q.empty()){
        point = q.front(); q.pop();
        for(int i=0; i<4; i++){
            x = point.first + dir[i][0];
            y = point.second + dir[i][1];

            if(x >= 0 && x < n && y >= 0 && y < m
            && box_2[x][y] != -1 && !visited[x][y]){
                q.push(make_pair(x,y));
                visited[x][y] = 1;
                box_2[x][y] = 1;
            }
        }
    }
}