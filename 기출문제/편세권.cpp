#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
int score_map[51][51];
int visited[51][51];
int dis[51][51];
vector<pair<int,int>> v;
vector<pair<int,int>> dir;

void bfs(int start_x, int start_y){
  queue<pair<int,int>> q;
  q.push(make_pair(start_x, start_y));
  visited[start_x][start_y] = 1;
  dis[start_x][start_y] = 0;

  pair<int,int> data;
  while(!q.empty()){
    data = q.front(); q.pop();
    int x = data.first, y = data.second;

    for(auto i : dir){
      int next_x = x + i.first, next_y = y + i.second;
      if(x >= 0 && x < n && y >= 0 && y < n && !visited[next_x][next_y]
      && dis[x][y] < 10){
        dis[next_x][next_y] = dis[x][y] + 1;
        visited[next_x][next_y] = 1;
        if(dis[next_x][next_y] <= 3) score_map[next_x][next_y] += 3;
        else score_map[next_x][next_y]++;
        q.push(make_pair(next_x, next_y));
      }
    }
  }
  //all clear
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      visited[i][j] = 0;
      dis[i][j] = 0;
    }
  }
}

int main(){
  int t, c, x, y;
  dir.push_back(make_pair(-1,0)); dir.push_back(make_pair(1,0));
  dir.push_back(make_pair(0,1)); dir.push_back(make_pair(0,-1));
  cin >> t;

  while(t--){
    cin >> n >> c;

    for(int i=0; i<c; i++){
      cin >> x >> y;
      v.push_back(make_pair(x,y));
    }

    for(auto i : v){
      bfs(i.first, i.second);
    }

    int idx_x = 0, idx_y = 0, max_score = 0;
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        if(score_map[i][j] > max_score){
          idx_x = i; idx_y = j; max_score = score_map[i][j];
        }
      }
    }
    cout << idx_x << " " << idx_y << " " << max_score << endl;
    //clear
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        score_map[i][j] = 0;
      }
    }
    v.clear();
  }
}
