#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int w, h;

int dir[8][2] = {{-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1}};

bool is_in(int x, int y){
    if(x >= 0 && y >= 0 && x < h && y < w){
        return true;
    }
    return false;
}

int main(){
    vector<int> answer_v;

    while(true){
        
        // 입력받기
        cin >> w >> h;

        // exit the program
        if(!w && !h) break;

        else{
            vector<vector<int>> map;
            vector<int> temp;
            vector<vector<int>> visited(h, vector<int>(w,0));
            
            // create map
            int data;
            for(int i=0; i<h; i++){
                for(int j=0; j<w; j++){
                    cin >> data;
                    temp.push_back(data);
                }
                map.push_back(temp);
                temp.clear();
            }

            // bfs 돌리기
            int answer = 0;
            for(int i=0; i<h; i++){
                for(int j=0; j<w; j++){
                    if(!visited[i][j] && map[i][j]){
                        
                        answer++;
                        // bfs 기능
                        queue<pair<int,int>> q;
                        q.push(make_pair(i,j));
                        visited[i][j] = 1;

                        while(!q.empty()){
                            pair<int,int> curr = q.front();
                            q.pop();
                            int x = curr.first, y = curr.second;

                            for(int k=0; k<8; k++){
                                int nx = x + dir[k][0];
                                int ny = y + dir[k][1];

                                if(is_in(nx,ny) && !visited[nx][ny] && map[nx][ny] == 1){
                                    visited[nx][ny] = 1;
                                    q.push(make_pair(nx,ny));
                                }
                            }
                        }
                    }
                }
            }
            answer_v.push_back(answer);

        }
    }

    for(auto i : answer_v){
        cout << i << endl;
    }

}