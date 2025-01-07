#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
#define MAX 101

int map[MAX][MAX];
int visited[MAX][MAX];
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
int n, m;
string input;

bool is_in(int x, int y){
    if(x >= 0 && y >= 0 && x < n && y < m){
        return true;
    }
    return false;
}

void bfs(){
    pair<int,int> p = make_pair(0,0); // 시작 좌표
    queue<pair<int,int>> q;
    q.push(p);
    visited[0][0] = 1;

    while(!q.empty()){
        p = q.front(); q.pop();
        int cur_x = p.first;
        int cur_y = p.second;

        for(int i=0; i<4; i++){
            int next_x = cur_x + dir[i][0];
            int next_y = cur_y + dir[i][1];
            if(map[next_x][next_y] && is_in(next_x, next_y)
            && !visited[next_x][next_y]){
                visited[next_x][next_y] = visited[cur_x][cur_y] + 1;
                q.push(make_pair(next_x, next_y));
            }
        }
    }
    

}

int main(){
    cin >> n >> m;

    for(int i=0; i<n; i++){
        cin >> input;
        for(int j=0; j<m; j++){
            map[i][j] = input[j] - '0';
        }
    }

    bfs();

    cout << visited[n-1][m-1] << endl;

    return 0;
}
