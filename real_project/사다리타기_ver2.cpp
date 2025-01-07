#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> ladder;
int visited[201][201];
int test, n, m, d;

void bfs(){
  int x = m-1, y = 2*d-2;

  visited[x][y] = 1;
  while(x > 0){
    if(ladder[x][y-1] == '+' && !visited[x][y-1]){
      y--;
      visited[x][y] = 1;
    }
    else if(ladder[x][y+1] == '+' && !visited[x][y+1]){
      y++;
      visited[x][y] = 1;
    }
    else if(ladder[x-1][y] == '+'){
      x--;
      visited[x][y] = 1;
    }
    // cout << "x = " << x << ", y = " << y << endl;
  }
  cout << (y+2) / 2 << "\n";
}

int main(){
  string str;
  cin >> test;

  for(int q=0; q<test; q++){
    cin >> n >> m >> d;

    for(int i=0; i<m; i++){
      for(int j=0; j<2*n; j++){
        visited[i][j] = 0;
      }
    }

    cin.ignore();                               // buffer clear
    for(int i=0; i<m; i++){                      // draw ladder
      getline(cin, str);
      ladder.push_back(str);
    }

    // for(auto i : ladder){
    //   cout << i << endl;
    // }

    // cout << ladder[1][0] << endl;             // + 자리 찾기
    // cout << ladder[m-1][2*n-2] << endl;

    bfs();
    ladder.clear();                              // 다음사다리 그리기 위해 비워주기
  }
}
