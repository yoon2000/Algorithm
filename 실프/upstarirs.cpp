#include <iostream>
using namespace std;

int main(){
  int t, stair, broke;
  cin >> t;


  for(int i=0; i<t; i++){
    cin >> stair >> broke;
    int first = broke / 2;
    int second = (stair - broke) / 2;

    int answer = first + second + 1;
    cout << answer << endl;
  }
}
