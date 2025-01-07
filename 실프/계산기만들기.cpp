#include <iostream>
#include <string>
#include <algorithm>
#include <deque>
using namespace std;

long long n, answer;

long long next_value();

long long cal(){
  deque<string> st1;
  deque<long long> st2;

  string data;
  while(n--){
    cin >> data;

    if(data[0] - '0' >= 0 && data[0] -'0'<= 9){
      st2.push_back(stoll(data));
    }
    else if(data == "("){
      st2.push_back(cal());
    }
    else if(data == ")"){
      while(!st1.empty()){
        string signal = st1.front(); st1.pop_front();
        long long b = st2.front(); st2.pop_front();
        long long a = st2.front(); st2.pop_front();

        if(signal == "+"){
          st2.push_front(a+b);
          // cout << "+++ = " << a+b << endl;
        }
        else if(signal == "-"){
          st2.push_front(b-a);
          // cout << "--- = " << a-b << endl;
        }
      }
      return st2.front();
    }
    else if(data == "*"){
      long long a = st2.back(); st2.pop_back();
      long long b = next_value();
      st2.push_back(a*b);
      // cout << "*** = " << a*b << endl;
    }
    else{
      st1.push_back(data);
    }
  }

  while(!st1.empty()){
    string signal = st1.front(); st1.pop_front();
    long long b = st2.front(); st2.pop_front();
    long long a = st2.front(); st2.pop_front();

    if(signal == "+"){
      st2.push_front(a+b);
      // cout << "+++ = " << a+b << endl;
    }
    else if(signal == "-"){
      st2.push_front(b-a);
      // cout << "--- = " << a-b << endl;
    }
  }
  return st2.front();
}

long long next_value(){
    string data;
    while(n--){
      cin >> data;

      if(data[0] - '0' >= 0 && data[0] -'0'<= 9){
        return stoll(data);
      }
      else if(data == "("){
        return cal();
      }
    }
  }


int main(){
  int test_num;
  cin >> test_num;

  while(test_num--){
    cin >> n;
    answer = cal();
    cout << answer << endl;
  }

}
