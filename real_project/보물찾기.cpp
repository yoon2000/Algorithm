/*
이동방향 진리표

before : 이전방향  map : 현재 제시된 방향

before == F 일경우  result = 지도이동

before == (R or L) 일경우
	1. if map == F, 	result = before
	2. if map == B, 	result = L 이면 R, R 이면 L
	3. if before == map, 	result = B
	4. else, 		result = F

before == B 일경우 result = map의 대칭방향


종료 조건 before == result 일때의 위치
*/

#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;

vector<vector<string> > map;

char reverse_dir(char dir){
  if (dir == 'F') return 'B';
  else if(dir == 'B') return 'F';
  else if(dir == 'R') return 'L';
  else return 'R';
}

char make_dir(char before, string data, pair<int,int> p){
  char curr = data[0];
  char dir;

  //dir 구하기
  if(before == 'F') dir = curr;
  else if(before == 'R' || before == 'L'){
    if(curr == 'F') dir = before;
    else if(curr == 'B') dir = reverse_dir(before);
    else if(before == curr) dir = 'B';
    else dir = 'F';
  }
  else if(before == 'B') dir = reverse_dir(curr);

  return dir;
}

pair<int,int> move_point(char dir, string data, pair<int,int> p){
  //실제 point값 바꾸기
  int dis = data[1] - '0';
  if (dir == 'F') return make_pair(p.first+dis, p.second);
  else if(dir == 'B') return make_pair(p.first-dis, p.second);
  else if(dir == 'R') return make_pair(p.first, p.second+dis);
  else return make_pair(p.first, p.second-dis);
}

int main(){
  int test_n;
  cin >> test_n;

  while(test_n--){
    int n;
    cin >> n;

    vector<string> temp;
    string data;
    for(int i=0; i<n; i++){
      for(int i=0; i<n; i++){
        cin >> data;
        temp.push_back(data);
      }
      map.push_back(temp);
      temp.clear();
    }

    vector<vector<set<char>>> dir_memo(n, vector<set<char> >(n));

    char before = 'B';
    pair<int,int> p(0, 0);
    data = map[p.first][p.second];
    char dir = make_dir(before, data, p);

    do{
        dir_memo[p.first][p.second].insert(dir);
        p = move_point(dir, data, p);

        before = dir;
        data = map[p.first][p.second];
        dir = make_dir(before, data, p);

        // cout << "dir_memo = " << dir_memo[p.first][p.second] << endl;
        // cout << "dir = " << dir << endl;
    }while(!dir_memo[p.first][p.second].count(dir));

    cout << p.first << " " << p.second << endl;
    map.clear();
  }

}
