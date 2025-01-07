#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> turn_right(int n, vector<string> v){
  vector<string> ret;
  string data;

  for(int i=0; i<n; i++){
    data = "";
    for(int j=n-1; j>=0; j--){
      data += v[j][i];
    }
    ret.push_back(data);
  }

  return ret;
}

int main(){
  int test_n;
  cin >> test_n;

  while(test_n--){
    int n, angle;
    cin >> n >> angle;

    vector<string> image;
    string data;
    for(int i=0; i<n; i++){
      cin >> data;
      image.push_back(data);
    }

    int turn_cnt = 0;
    if(angle > 0){
      turn_cnt = angle/90;
    }
    else if(angle < 0){
      angle += 360;
      turn_cnt = angle/90;
    }

    while(turn_cnt--){
      image = turn_right(n, image);
    }

    for(auto i:image){
      cout << i << endl;
    }
  }

}
