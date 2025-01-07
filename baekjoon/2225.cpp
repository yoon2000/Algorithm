#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= k; i++) {
        for (int j = 0; j <= n; j++) {
            for (int l = 0; l <= j; l++) {
                dp[i][j] += dp[i - 1][j - l];
                dp[i][j] %= 1000000000; // 나머지 연산 처리
            }
        }
    }

    cout << dp[k][n] << endl;

    return 0;
}
