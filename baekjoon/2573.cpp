#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

vector<vector<int>> melt_down(vector<vector<int>> map);
int number_area(vector<vector<int>> map);
bool is_in(int x, int y, int n, int m);

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> map(n, vector<int>(m, 0));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
        }
    }

    int years = 0;
    int area = number_area(map);

    while(area < 2){
        map = melt_down(map);
        area = number_area(map);
        years++;

        // 모든 빙하가 녹으면 종료
        if(area == 0){
            cout << 0 << endl;
            return 0;
        }
    }

    cout << years << endl;
}

vector<vector<int>> melt_down(vector<vector<int>> map){
    vector<vector<int>> ret_map(map);

    int n = map.size();
    int m = map[0].size();

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j]){
                int data = map[i][j];
                for(int k=0; k<4; k++){
                    int next_x = i + dir[k][0];
                    int next_y = j + dir[k][1];

                    if(is_in(next_x, next_y, n, m)){
                        int neighbor = map[next_x][next_y];
                        if(neighbor == 0) data--;
                    }
                }
                if(data <= 0) ret_map[i][j] = 0;
                else ret_map[i][j] = data;
            }
        }
    }

    return ret_map;
}

int number_area(vector<vector<int>> map){
    queue<pair<int,int>> q;

    int n = map.size();
    int m = map[0].size();
    int area = 0;
    vector<vector<int>> visited(n, vector<int>(m,0));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j] && !visited[i][j]){
                area++;
                visited[i][j] = 1;

                //bfs
                q.push(make_pair(i,j));
                while(!q.empty()){
                    pair<int,int> data = q.front(); q.pop();
                    int x = data.first;
                    int y = data.second;

                    for(int k=0; k<4; k++){
                        int next_x = x + dir[k][0];
                        int next_y = y + dir[k][1];
                        if(!visited[next_x][next_y] && map[next_x][next_y]
                        && is_in(next_x, next_y, n, m)){
                            q.push(make_pair(next_x, next_y));
                            visited[next_x][next_y] = 1;
                        }
                    }
                }
            }
        }
    }

    return area;
}

bool is_in(int x, int y, int n, int m){
    if(x >= 0 && y >= 0 && x < n && y < m) return true;
    return false;
}