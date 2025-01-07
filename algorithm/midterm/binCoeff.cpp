#include <iostream>
#include <vector>
#include <limits.h>

#define MAX_SIZE 30
using namespace std;

int binCoeff(int n, int r){
    vector<vector<int>> dp(MAX_SIZE, vector<int>(MAX_SIZE, 0));

    for(int i=0; i<=n; i++){
        for(int j=0; j<=min(i,r); j++){
            if(j == 0 || j == n){
                dp[i][j] = 1;
            }
            else {
                dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
            }
        }
    }

    return dp[n][r];

}


int main(){
    int answer = binCoeff(10, 2);
    cout << answer << endl;
}