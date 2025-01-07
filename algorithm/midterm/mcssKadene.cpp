#include <iostream>
#include <vector>
using namespace std;

void mcss(int arr[], int n){
    vector<int> dp; dp.push_back(arr[0]);
    int start = 0, end = 0, temp_start = 0;

    for(int i=1; i<n; i++){
        if(dp[i-1] + arr[i] < arr[i]){
            temp_start = i;
            dp.push_back(arr[i]);
        }
        else{
            dp.push_back(dp[i-1] + arr[i]);
        }

        if(dp[i] > dp[end]){
            start = temp_start;
            end = i;
        }
    }

    cout << start << " " << end << " " << dp[end] << endl;

}

int main(){
    int n = 10;
    int arr[10] = { 5, -7, 2, 3, -4, 5, 2, -7, 8, -7 };

    mcss(arr, n);
}