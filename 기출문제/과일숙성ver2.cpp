#include <iostream>
#include <vector>
#include <queue>
using namespace std;


//visited 초기화 해야함
int dir[4][2] = {{0,-1}, {0,1}, {1,0}, {-1,0}};
vector<vector<int>> box;
int dis[501][501];
int n, m;
queue<pair<int,int>> q;

bool check_box();
void pass_one_day();
void bfs();

int main(){
    int t;
    cin >> t;

    while(t--){
        cin >> n >> m;
        int data;

        vector<int> temp;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                dis[i][j] = 0;
                cin >> data;
                if(data == 1){
                    q.push(make_pair(i,j));
                    dis[i][j] = 1;
                } 
                temp.push_back(data);
            }
            box.push_back(temp);
            temp.clear();
        }

        // 사과 익히기
        bfs();
        
        // cout << endl;
        int max_dis = 0;
        bool put_apple = false;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                // cout << dis[i][j] << " ";
                max_dis = max(max_dis, dis[i][j]);
                if(box[i][j] != -1 && dis[i][j] == 0){
                    put_apple = true;
                }
            }
            // cout << endl;
        }
        if(put_apple) cout << -1 << endl;
        else cout << max_dis - 1 << endl;

        box.clear();
    }
}



         
void bfs(){
    vector<vector<int>> visited(n,vector<int>(m,0));

    pair<int,int> point;
    int x, y;
    while(!q.empty()){
        point = q.front(); q.pop();
        for(int i=0; i<4; i++){
            x = point.first + dir[i][0];
            y = point.second + dir[i][1];

            if(x >= 0 && x < n && y >= 0 && y < m
            && box[x][y] == 0 && !visited[x][y]){
                q.push(make_pair(x,y));
                visited[x][y] = 1;
                if(!dis[x][y]) dis[x][y] = dis[point.first][point.second] + 1;
                else{
                    dis[x][y] = min(dis[x][y], dis[point.first][point.second] + 1);
                }
            }
        }
    }
}