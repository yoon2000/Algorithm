#include <iostream>
#include <queue>
#include <string>
#include <cstdlib>
#define MAX 101
using namespace std;

//bfs를 사용해서 풀어야함! dfs사용시 시간초과.

//global variable
int n,m;
int miro[MAX][MAX];
int check[MAX][MAX];
int visited[MAX][MAX];

//direction
class direct{
public:
  int x;
  int y;
};

direct dir[4];

queue<pair<int,int>> q; //탑색 좌표 저장용 queue

void bfs(int start_x, int start_y){
  int next_x, next_y;
  q.push(make_pair(start_x, start_y));

  check[start_y][start_x] = 1;
  visited[start_y][start_x] = 1;

  while(!q.empty()){
    pair<int,int> data = q.front();
    int x = data.first;
    int y = data.second;
    q.pop();

    //방향 탐색
    for(int i=0; i<4; i++){
      next_x = x + dir[i].x;
      next_y = y + dir[i].y;

      //범위 이탈시 건너뛰기
      if((0 <= next_x && next_x < m) && (0 <= next_y && next_y < n)
      && miro[next_y][next_x] == 1 && !visited[next_y][next_x]){

        check[next_y][next_x] = check[y][x] + 1;
        q.push(make_pair(next_x, next_y));
        visited[next_y][next_x] = 1;
      }
    }
  }
}

int main(){
  dir[0].y = 0; dir[0].x = 1; //right
  dir[1].y = 1; dir[1].x = 0; //down
  dir[2].y = 0; dir[2].x = -1; //left
  dir[3].y = -1; dir[3].x = 0; //up

  int t;
  string data;
  cin >> t;
  for(int k=0; k<t; k++)
  {
    cin >> n >> m;
    //miro input
    for(int i=0; i<n; i++){
      cin >> data;
      for(int j=0; j<m; j++){
        miro[i][j] = data[j] - '0';
        visited[i][j] = 0;
      }
    }

    bfs(0,0);

    //check 출력
    // for(int i=0; i<n; i++){
    //   for(int j=0; j<m; j++){
    //     cout << check[i][j] << " ";
    //   }
    //   cout << endl;
    // }

    cout << check[n-1][m-1] << endl;
  }
}
