#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <string>
using namespace std;

// 거꾸로 올라가면서 탐색하여 풀기 !

int test_num, n, m, d;
vector<string> arr;
int visited[201][201] = {0,};
int answer;

int bfs(int start){
  int cnt = 0;
  int start_x, start_y;
  int idx;
  queue<pair<int,int>> q;

  start_x = 2*start - 2;
  start_y = 0;

  cout << start_x << " " << start_y << endl;
  q.push(make_pair(start_x, start_y));               // 시작 좌표 방문 표시 및 큐에 넣기
  visited[start_y][start_x] = 1;

  pair<int,int> curr;
  while(!q.empty()){
    curr = q.front();
    q.pop();

    if(curr.first+1 < 2*n && !visited[curr.second][curr.first+1] && arr[curr.second][curr.first+1] == '+'){      // right
      q.push(make_pair(curr.first+1, curr.second));
      visited[curr.second][curr.first+1] = 1;
    }

    else if(curr.first > 0 && !visited[curr.second][curr.first-1] && arr[curr.second][curr.first-1] == '+'){      // left
      q.push(make_pair(curr.first+1, curr.second));
      visited[curr.second][curr.first-1] = 1;
    }

    else{                                                          // down
      if(curr.second < m-1 && !visited[curr.second+1][curr.first] &&){
        q.push(make_pair(curr.first, curr.second+1));
        visited[curr.second+1][curr.first] = 1;
        if(curr.second+1 == m-1) idx = curr.first;
      }
    }
  }

  // for(int i=0; i<2*n; i++){
  //   if(visited[m-1][i] == 1){
  //     idx = i;
  //     break;
  //   }
  // }
  cout << "idx = " << idx << endl;
  return idx/2 + 1;
}

int main(){
  cin >> test_num;
  string str;

  for(int quit=0; quit < test_num; test_num++){
    cin >> n >> m >> d;

    for(int i=0; i<m+1; i++){                             // 사다리 그리기
      getline(cin, str);
      arr.push_back(str);
    }

    fill(&visited[0][0], &visited[201][201], 0);
    for(int i=1; i<n+1; i++){
      if(bfs(i) == d){
        cout << i << "\n";
        fill(&visited[0][0], &visited[201][201], 0);
      }
    }
  }
}
