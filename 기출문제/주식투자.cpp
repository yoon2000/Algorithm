#include <iostream>
#include <stack>
using namespace std;

// 그래프를 거꾸로 접근하자?

// 고점에서 팔았는데, 더 높은 고점이 나타남.
// 고점에서 팔고 떨어졌는데 고점은 아니지만 떨어진 값보다는 커짐.

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  long long test_num, d, data;
  cin >> test_num;

  while(test_num--){
    cin >> d;

    stack<long long> graph;
    for(int i=0; i<d; i++){
      cin >> data;
      graph.push(data);
    }

    long long top = graph.top(), revenue = 0;

    while(!graph.empty()){
      data = graph.top();
      graph.pop();
      if(data > top) top = data;
      else revenue += top - data;
    }
    cout << revenue << endl;
  }

}
