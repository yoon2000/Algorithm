#include <iostream>
#include <vector>
using namespace std;

void kadane(int n, vector<int> a){
    vector<int> dp;
    dp.push_back(a[0]);
    int start = 0, end = 0;
    int temp_start = 0;

    for(int i=1; i<n; i++){
        if(a[i] > dp[i-1] + a[i]){
            dp.push_back(a[i]);
            temp_start = i;
        }
        else{
            dp.push_back(dp[i-1] + a[i]);
        }

        if(dp[i] > dp[end]){
            start = temp_start;
            end = i;
        }
    }

    int max_num = dp[0];
    for(int i=1; i<n; i++){
        if(dp[i] > max_num)
            max_num = dp[i];
    }

    while(!a[start]){
        start++;
    }

    if(max_num <= 0){
        max_num = 0;
        start = -1;
        end = -1;
    }

    cout << max_num << " " << start << " " << end << endl;
}

int main(){
    int t;
    cin >> t;
    
    while(t--){
        int n, data;
        cin >> n;

        vector<int> a;

        for(int i=0; i<n; i++){
            cin >> data;
            a.push_back(data);
        }

        kadane(n, a);
    }
}