#include <iostream>
#include <stack>
using namespace std;

int main(){
  long long t, d;
  cin >> t;

  stack<long long> graph;
  long long data, top;

  while(t--){
    cin >> d;
    for(int i=0; i<d; i++){
      cin >> data;
      graph.push(data);
    }

    top = graph.top();
    graph.pop();
    long long revenue = 0;

    while(!graph.empty()){
      data = graph.top();
      graph.pop();

      if(data > top) top = data;
      else revenue += (top - data);
    }
    cout << revenue << endl;

  }
}
