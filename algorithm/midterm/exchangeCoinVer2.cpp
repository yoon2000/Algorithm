#include <iostream>
#include <vector>
using namespace std;

int fib(int change, vector<int> coins){
    vector<int> dp(change+1, 0);
    dp[0] = 1;
    
    for(auto coin : coins){
        for(int i=coin; i<change+1; i++){
            dp[i] += dp[i - coin];
        }
    }

    return dp[change];
}

int main(){
    vector<int> coins = {1, 2, 3};
    cout << fib(4, coins) << endl;
}