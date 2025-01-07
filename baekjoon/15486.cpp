#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t[1500002];
int p[1500002];
int dp[1500002];
int n;


int main(){
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> t[i];
        cin >> p[i];
    }

    // DP
    int pay_day;
    for(int i=0; i <= n+1; i++){
        pay_day = i + t[i];
        
        // 퇴사전에 끝낼 수 있는 상담일 경우
        if(pay_day < n+1){
            dp[pay_day] = max(dp[i] + p[i], dp[pay_day]);
        }

        // 다음날에 정산하기
        dp[i+1] = max(dp[i], dp[i+1]);
    }

    cout << dp[n+1] << endl;
}