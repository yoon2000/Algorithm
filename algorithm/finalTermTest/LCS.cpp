#include <iostream>
#include <vector>
#include <string>
using namespace std;

int LCS(string x, string y){
	int m = x.size();
	int n = y.size();

    x = " " + x;
    y = " " + y; 

    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

	for(int i=1; i<=m; i++){
		for(int j=1; j<=n; j++){
			if(x[i] == y[j]){
                // 같을경우 왼쪽 대각선 위에서 +1 한값으로 설정
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                // 틀릴경우 위, 왼쪽 값중 MAX 값으로 설정
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
		}
	}

    return dp[m][n];
}

int main(){
    string str1, str2;

    cin >> str1 >> str2;

    cout << LCS(str1, str2) << endl;
}