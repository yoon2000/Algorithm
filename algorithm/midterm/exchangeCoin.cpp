#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int fib(int n){
    vector<int> dp(n+1, INT_MAX);
    dp[0] = 0;
    
    int coin[5] = {1, 5, 10, 21, 25};

  
    for(int i=1; i<n+1; i++){
        for(int j=0; j<5; j++){
            if(i >= coin[j] && dp[i-coin[j]] != INT_MAX){
                dp[i] = min(dp[i-coin[j]] + 1, dp[i]);
            }
        }
    }

    return dp[n];
}


int main(){
    cout << fib(63) << endl;
}