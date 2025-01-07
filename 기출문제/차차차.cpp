// 동적 계획법을 활용하기!
// 2번 전에 것까지 확인하면서 가기?
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> map;
int score[101][5];
int n;

int cal_score(int x, int y){
  int point =  map[x][y];                       // 아이템 점수 더하기

  if(x == n-1){                                    // 첫번째 줄 일경우
    if(y-1 >= 0 && map[x][y-1] == 1) point++;      // 왼쪽에 장애물 있을경우 점수 +
    if(y+1 < 5 && map[x][y+1] == 1) point++;       // 오른쪽에 장애물 점수 +
    return point;
  }

  else{                                            // 둘째줄 줄일경우
    if(y-1 >= 0 && map[x][y-1] == 1) point++;      // 왼쪽에 장애물 있을경우 점수 +
    if(y+1 < 5 && map[x][y+1] == 1) point++;       // 오른쪽에 장애물 점수 +

    int left = 0, straight = score[x+1][y], right = 0;
    if(y-1 >= 0) left = score[x+1][y-1];
    if(y+1 < 5) right = score[x+1][y+1];
    point += max({left, straight, right});
    point += score[x][y];
    return point;
  }

}

int main(){
  int t;
  cin >> t;

  for(int q=0; q<t; q++){

    for(int i=0; i<101; i++){
      for(int j=0; j<5; j++){
        score[i][j] = 0;
      }
    }

    cin >> n;

    int data;
    vector<int> temp;
    for(int i=0; i<n; i++){
      for(int j=0; j<5; j++){
        cin >> data;
        temp.push_back(data);
      }
      map.push_back(temp);
      temp.clear();
    }

    // 첫째줄 score 구하기
    for(int i=1; i<4; i++){
      if(map[n-1][i] != 1){
        score[n-1][i] = cal_score(n-1, i);
      }
    }
    for(int i=n-2; i>=0; i--){
      for(int j=0; j<5; j++){
        if(map[i][j] != 1){
          score[i][j] = cal_score(i,j);
        }
      }
    }

    // cout << "-------------score value check-------------" << endl;
    // for(int i=0; i<n; i++){
    //   for(int j=0; j<5; j++){
    //     cout << score[i][j] << " ";
    //   }
    //   cout << endl;
    // }

    int answer = 0;
    for(int i=0; i<5; i++){
      answer = max(answer, score[0][i]);
    }
    cout << answer << '\n';
    // cout << *max_element(score[0], score[0]+5) << '\n';
    map.clear();

  }
}
