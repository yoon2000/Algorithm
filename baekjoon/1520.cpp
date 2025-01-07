#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 전역으로 사용할 변수들
int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
int n, m;

// 사용할 함수들 선언
bool is_in(int x, int y);
void bfs(int x, int y, vector<vector<int>>& v);

int main(){
    int data;
    cin >> m >> n;

    vector<vector<int>> v;
    vector<int> temp;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> data;
            temp.push_back(data);
        }
        v.push_back(temp);
        temp.clear();
    }

    bfs(0, 0, v);
}

// ---------- 실제 함수 구현 ------------

bool is_in(int x, int y){
    return x >= 0 && y >= 0 && x < m && y < n;    
}
void bfs(int x, int y, vector<vector<int>>& v) {
    vector<vector<int>> visited(m, vector<int>(n, 0));
    vector<vector<int>> dp(m, vector<int>(n, 0));

    pair<int,int> start = make_pair(x, y);
    queue<pair<int,int>> q;

    q.push(start);
    dp[x][y] = 1; // 시작 위치에서는 경로의 수가 1이므로 1로 초기화
    visited[x][y] = 1; // 시작 위치를 방문했음을 표시

    while (!q.empty()) {
        pair<int,int> curr = q.front(); q.pop();
        int x = curr.first;
        int y = curr.second;
        int curr_height = v[x][y];

        for (int i = 0; i < 4; i++) {
            int next_x = x + dir[i][0];
            int next_y = y + dir[i][1];

            if (!is_in(next_x, next_y))
                continue;
            
            int next_height = v[next_x][next_y];

            if (next_height < curr_height) {
                // 해당 위치로 도달하는 경로 수를 누적하여 갱신
                dp[next_x][next_y] += dp[x][y];
                
                if (!visited[next_x][next_y]) { // 방문한 적 없는 경우에만 큐에 추가
                    q.push(make_pair(next_x, next_y));
                    visited[next_x][next_y] = 1; // 방문했음을 표시
                }
            }
        }
    }

    cout << dp[m-1][n-1] << endl;
}


// void bfs(int x, int y, vector<vector<int>> v){
//     vector<vector<int>> visited(m, vector<int>(n,0));
//     vector<vector<int>> dp(m, vector<int>(n,0));
//     pair<int,int> start = make_pair(x, y);
//     queue<pair<int,int>> q;

//     q.push(start);
//     visited[x][y] = 1;
//     dp[x][y] = 1;
 
//     while(!q.empty()){
//         pair<int,int> curr = q.front(); q.pop();
//         int x = curr.first;
//         int y = curr.second;
//         int curr_height = v[x][y];
        
//         for(int i=0; i<4; i++){
//             int next_x = x + dir[i][0];
//             int next_y = y + dir[i][1];

//             if(!is_in(next_x, next_y)){
//                 continue;
//             }
//             int next_height = v[next_x][next_y];

//             if(next_height < curr_height){
//                 if(next_x == m-1 && next_y == n-1){
//                     dp[next_x][next_y] += 1;
//                 } else {
//                     dp[next_x][next_y] = dp[x][y];
//                 }

//                 if(!visited[next_x][next_y]) {
//                     q.push(make_pair(next_x, next_y));
//                     visited[next_x][next_y] = 1;
//                 }
//             }
//         }
//         visited[x][y] = 1;
//     }

//     cout << dp[m-1][n-1] << endl;
// }