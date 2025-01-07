#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[1001];
int dp[1001];

int main(){
    cin.sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    // 배열 입력 받기
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int out = 0;

    // DP 사용하면서 긴 구간 탐색
    for(int i=0; i<n; i++){
        dp[i] = 1;
        for(int j=0; j<i; j++){
            if(arr[i] < arr[j]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        out = max(out, dp[i]);
    }

    cout << out << endl;
}