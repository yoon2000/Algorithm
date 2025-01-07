#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

//모든 오브젝트들이 맵에 영향을 다 미쳤을 경우 반복을 중단하고 단순 계산 실시.

/*

*/

int main(){
  int test_n;
  cin >> test_n;

  while(test_n--){
    int n, m, a, b, r, c, total_score = 0;
    cin >> n >> m;
    cin >> a >> b;

    vector<vector<int>> map(n, vector<int>(n, 0));

    //poison
    for(int i=0; i<a; i++){
      cin >> r >> c;

      int arr_m = max({r, c, n-r, n-c});
      if(arr_m < m){
        total_score -= (m-arr_m);
        for(int k = 1; k <= arr_m; k++){
          int start_r = r-k;
          int start_c = c-k;
          for(int i = start_r; i < start_r + (2*k+1); i++){
            for(int j = start_c; j < start_c + (2*k+1); j++){
              if(i >= 0 && i < n && j >=0 && j < n){
                map[i][j] -= 1;
              }
            }
          }
        }
      }

      else{
        for(int k = 1; k <= m; k++){
          int start_r = r-k;
          int start_c = c-k;
          for(int i = start_r; i < start_r + (2*k+1); i++){
            for(int j = start_c; j < start_c + (2*k+1); j++){
              if(i >= 0 && i < n && j >=0 && j < n){
                map[i][j] -= 1;
              }
            }
          }
        }
      }

    }

    //heal
    for(int i=0; i<b; i++){
      cin >> r >> c;

      int arr_m = max({r+c, (n-r)+c, r+(n-c), 2*n-r-c});
      if(arr_m < m){
        total_score += (m-arr_m);
        for(int k=1; k <= arr_m; k++){
          int mid = (2*k+1) / 2;
          int start_r = r-k;
          int start_c = c-k;
          for(int i = start_r; i < start_r + (2*k+1); i++){
            int abs_i = abs(i-r);
            for(int j = start_c; j < start_c + (2*k+1); j++){
              if(i >= 0 && i < n && j >=0 && j < n){
                int abs_j = abs(j-c);
                if(abs_j <= (mid - abs_i)){
                  map[i][j] += 1;
                }
              }
            }
          }
        }
      }

      else{
        for(int k=1; k <= m; k++){
          int mid = (2*k+1) / 2;
          int start_r = r-k;
          int start_c = c-k;
          for(int i = start_r; i < start_r + (2*k+1); i++){
            int abs_i = abs(i-r);
            for(int j = start_c; j < start_c + (2*k+1); j++){
              if(i >= 0 && i < n && j >=0 && j < n){
                int abs_j = abs(j-c);
                if(abs_j <= (mid - abs_i)){
                  map[i][j] += 1;
                }
              }
            }
          }
        }
      }

    }

    //print
    for(auto i : map){
      for(auto j : i){
        cout << j + total_score << " ";
      }
      cout << endl;
    }

  }

}
