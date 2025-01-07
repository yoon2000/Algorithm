#include <iostream>
#include <string>
using namespace std;

int fac(int n){
    if(n <= 1){
        return 1;
    }
    else{
        int ret = n * fac(n-1);
        while(ret % 10 == 0){
            ret /= 10;
        }
        return ret % 10000;
    }
}

int main(){
    int t, data;
    cin >> t;

     while(t--){
        cin >> data;

        // string answer = to_string(fac(data));
        int answer = fac(data) % 1000;

        cout << answer << endl;
     }
}