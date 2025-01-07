#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
  int test_n;
  cin >> test_n;

  while(test_n--){
    int n, a, c, need_sz, answer = 0;
    cin >> n;

    vector<pair<int,int>> v(101, make_pair(0, 0));
    // first = 사이즈 값, second = 원소개수값

    for(int i=0; i<n; i++){

      cin >> a >> c;
      need_sz = v[a].second + c;

      if(need_sz > v[a].first){
        double result = log2(need_sz);
        int cmp = result;

        if(need_sz <= 2){
          v[a].first = 2;
        }
        else{
          v[a].first = pow(2, cmp+1);
        }
        answer += v[a].second;
        v[a].second += c;
      }
      else{
        v[a].second += c;
      }
    }

    cout << answer << endl;

  }
}
