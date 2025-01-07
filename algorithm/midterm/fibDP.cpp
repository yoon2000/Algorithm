#include <iostream>
using namespace std;

int memo[1001];

int fib(int n){
    if(n <= 1) return n;
    else if(memo[n]){
        return memo[n];
    }
    else{
        for(int i=2; i<n+1; i++){
            if(!memo[i]){
                memo[i] = memo[i-1] + memo[i-2];
            }
        }
        return memo[n];
    }
}

int main(){
    memo[0] = 0;
    memo[1] = 1;

    cout << fib(9) << endl;
    
}