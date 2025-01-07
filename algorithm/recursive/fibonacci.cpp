#include <iostream>
using namespace std;

int fib(int n){
    if(n == 0){
        return 0;
    }
    else if(n == 1){
        return 1;
    }
    else{
        return fib(n-2) + fib(n-1);
    }
}

int main(){
    int t, data;
    cin >> t;

     while(t--){
        cin >> data;
        cout << fib(data) << endl;
     }
}