#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

int n;
int dir[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};

bool is_in(int x, int y){
    if(x >= 0 && y >= 0 && x < n && y < n){
        return true;
    }
    return false;
}

int main(){
    cin >> n;
    
    vector<vector<int>> map;
    vector<vector<int>> visited(n, vector<int>(n, 0));

    // map 입력
    string data; vector<int> temp;
    cin.ignore();
    for(int i=0; i<n; i++){
        getline(cin, data);
        for(int j=0; j<n; j++){
            temp.push_back(data[j] - '0');
        }
        map.push_back(temp);
        temp.clear();
    }

    // bfs 돌기
    int x, y, nx, ny;
    vector<int> house_cnt;
    int house_num;
    pair<int,int> curr;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(map[i][j] && !visited[i][j]){
                house_num = 1;
                visited[i][j] = 1;
                queue<pair<int,int>> q;
                q.push(make_pair(i,j));
                
                while(!q.empty()){
                    curr = q.front(); q.pop();
                    x = curr.first;
                    y = curr.second;

                    for(int k=0; k<4; k++){
                        nx = x + dir[k][0];
                        ny = y + dir[k][1];
                        
                        if(is_in(nx,ny) && !visited[nx][ny] && map[nx][ny]){
                            house_num++;
                            visited[nx][ny] = 1;
                            q.push(make_pair(nx,ny));
                        }
                    }
                }

                house_cnt.push_back(house_num);
            }
        }
    }
    sort(house_cnt.begin(), house_cnt.end());
    cout << house_cnt.size() << '\n';
    for(auto i : house_cnt){
        cout << i << '\n';
    }

}