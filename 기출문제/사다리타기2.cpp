#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;

vector<string> ladder;
vector<int> answer;
int visited[201][201];
int n, m, d;

void bfs_helper(int idx_x, int idx_y){

  vector<vector<int>> in_visited(m ,vector<int>(2*n-1,0));
  int in_vitited[n][m]{};

  while(idx_x != 0){
    if(idx_y+1 < 2*n-1 && ladder[idx_x][idx_y+1] == '+' && !in_visited[idx_x][idx_y+1]){   //right
      idx_y++;
      in_visited[idx_x][idx_y] = 1;
    }
    else if(idx_y-1 >= 0 && ladder[idx_x][idx_y-1] == '+' && !in_visited[idx_x][idx_y-1]){  //left
      idx_y--;
      in_visited[idx_x][idx_y] = 1;
    }
    else{
      idx_x--;
      in_visited[idx_x][idx_y] = 1;
    }
  }
  answer.push_back((idx_y+2) / 2);
}

void bfs(){
  int idx_x = m-1;
  int idx_y = 2*d-2;

  while(ladder[idx_x][idx_y] != '?'){
    if(idx_y+1 < 2*n-1 && ladder[idx_x][idx_y+1] == '+' && !visited[idx_x][idx_y+1]){   //right
      idx_y++;
      visited[idx_x][idx_y] = 1;
    }
    else if(idx_y-1 >= 0 && ladder[idx_x][idx_y-1] == '+' && !visited[idx_x][idx_y-1]){  //left
      idx_y--;
      visited[idx_x][idx_y] = 1;
    }
    else{
      idx_x--;
      visited[idx_x][idx_y] = 1;
    }
  }
  //straight
  bfs_helper(idx_x, idx_y);
  //right
  if(idx_y + 2 < 2*n-1) bfs_helper(idx_x, idx_y + 2);
  //left
  if(idx_y - 2 >= 0) bfs_helper(idx_x, idx_y - 2);
}

int main(){
  int test_num;
  cin >> test_num;

  string data;

  while(test_num--){
    cin >> n >> m >> d;

    for(int i=0; i<m; i++){
      cin >> data;
      ladder.push_back(data);
      for(int j=0; j<2*n-1; j++){
        visited[i][j] = 0;
      }
    }


    bfs();

    sort(answer.begin(), answer.end());
    for(auto i : answer){
      cout << i << " ";
    }
    cout << endl;

    ladder.clear();
    answer.clear();
  }

}
