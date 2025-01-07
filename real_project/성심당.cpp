/*
2
5 2
0 0 0 0 0
1 0 0 0 1
0 0 0 0 0
0 1 0 0 0
0 0 0 0 1
2 3
4 4
5 3
0 0 0 0 1
1 0 0 0 0
0 0 0 0 0
0 1 0 0 0
0 0 0 1 0
2 3
4 3
5 1

주의 사항
1. 열이나 행 작은순서 숙소로 먼저들어감
2. 모든사람들이 이동후에 도착한사람검사후 이동불가지역으로 설정
*/

#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

int dir[4][2] = {{-1,0}, {0,-1}, {0,1}, {1,0}};
set<pair<int,int>> check_in_house;
int arrive[16][16];
int market_loc[16][16];

pair<int,int> bfs(int start_x, int start_y, vector<pair<int,int>> house, int n){
  vector<vector<int>> visited(16, vector<int>(16,0));
  vector<vector<int>> distance(16, vector<int>(16,0));

  pair<int,int> point;
  visited[start_x][start_y] = 1;
  queue<pair<int,int>> q;
  q.push(make_pair(start_x, start_y));

  int x, y;
  while(!q.empty()){
    point = q.front();
    q.pop();
    for(int i=0; i<4; i++){
      int x = point.first + dir[i][0];
      int y = point.second + dir[i][1];
      if(x >= 0 && x < n && y >= 0 && y < n && !visited[x][y]){
        q.push(make_pair(x,y));
        visited[x][y] = 1;
        distance[x][y] = distance[point.first][point.second] + 1;
      }
    }
  }

  int min_v = 9999;
  pair<int,int> destination;
  for(auto i : house){
    int x = i.first; int y = i.second;
    if(!arrive[x][y]){
      min_v = min(min_v, distance[x][y]); 
    }
  }
  for(auto i : house){
    int x = i.first; int y = i.second;
    if(distance[x][y] == min_v && !arrive[x][y]){
      destination = make_pair(x, y);
      arrive[x][y] = 1;
      break;
    }
  }
  return destination;
}

pair<int,int> move_one(pair<int,int> person, pair<int,int> market, int n){
  vector<vector<int>> visited(16, vector<int>(16,0));
  vector<vector<int>> distance(16, vector<int>(16,9999));

  queue<pair<int,int>> q;
  visited[market.first][market.second] = 1;
  distance[market.first][market.second] = 0;
  q.push(market);

  bool escape = false;
  while(!q.empty()){

    pair<int,int> data = q.front(); q.pop();
    for(int i=0; i<4; i++){
      int x = data.first + dir[i][0]; int y = data.second + dir[i][1];

      if(x >= 0 && y >= 0 && x < n && y < n 
        && !visited[x][y] && !arrive[x][y]){

        q.push(make_pair(x, y));
        visited[x][y] = 1;
        distance[x][y] = distance[data.first][data.second] + 1;
        if(x == person.first && y == person.second){
          escape = true;
        }
      }
    }
    if(escape){
      break;
    }

  }

  int min_dis = 9999;
  for(int i=0; i<4; i++){
    int x = person.first + dir[i][0];
    int y = person.second + dir[i][1];
    if(x >= 0 && y >= 0 && x < n && y < n && !arrive[x][y]){
      min_dis = min(min_dis, distance[x][y]);
    }
  }
  pair<int,int> ret;
  for(int i=0; i<4; i++){
    int x = person.first + dir[i][0];
    int y = person.second + dir[i][1];
    if(x >= 0 && y >= 0 && x < n && y < n
    && !arrive[x][y] && distance[x][y] == min_dis){
      ret = make_pair(x,y);
    }
  }
  return ret;
}

int main(){
  int t;
  cin >> t;

  while(t--){
    int n, m, data;
    cin >> n >> m;

    vector<pair<int,int>> house;
    vector<vector<int>> map;
    vector<int> temp;

    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        cin >> data;
        if(data == 1){
          house.push_back(make_pair(i, j));
        }
        temp.push_back(data);

        //arrive, market_loc 초기화
        arrive[i][j] = 0;
        market_loc[i][j] = 0;
      }
      map.push_back(temp);
      temp.clear();
    }

    vector<pair<int,int>> market;
    int x, y;
    for(int i=0; i<m; i++){
      cin >> x >> y;
      market_loc[x][y] = 1;
      market.push_back(make_pair(x-1,y-1));
    }

    vector<pair<int,int>> person;
    for(auto i : market){
      person.push_back(bfs(i.first, i.second, house, n));
    }

    //사람들 시간에 따라서 이동시키기
    set<int> arr_person;
    int minute = 0;

    bool escape = false;
    while(arr_person.size() != m){
      for(int i=0; i<minute+1; i++){
        // 도착하지 않은 사람만 한칸 이동 시키기
        if(!arr_person.count(i)){
          // cout << i << "번째 사람 이동 = ";
          person[i] = move_one(person[i], market[i], n);
        
          // 자신이 원하는 식당에 도착하면 도착한 사람 집합에 추가해주기
          if(person[i] == market[i]){
            arr_person.insert(i);
          }
        }

      }
      for(int i=0; i<minute+1; i++){
        // 이동칸이 market일 경우 못지나가는 길로 만들기
        if(market_loc[person[i].first][person[i].second]){
          arrive[person[i].first][person[i].second] = 1;
          }
      }
      minute++;
    }
    cout << minute + 1 << endl;
  }
}
