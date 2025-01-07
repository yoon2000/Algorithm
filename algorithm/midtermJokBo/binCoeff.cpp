#include <iostream>
#include <vector>
using namespace std;

int binCoeff(int n, int k){
    vector<vector<int>> dp(n+1, vector<int>(k+1, 0));

    for(int i=0; i<=n; i++){
        for(int j=0; j<=min(i, k); j++){
            if(j == 0 || j == n){
                dp[i][j] = 1;
            }
            else{
                dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]) % 10000;
            }
        }
    }

    return dp[n][k] % 1000;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;

        int answer = binCoeff(n, k);
        cout << answer << endl;
    }
}