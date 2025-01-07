#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int fib(int k, vector<int> coins){
    if(k < 0) return INT_MAX;
    else if(k == 0) return 0;
    else{
        int min_value = INT_MAX;
        for(auto coin : coins){
            if(k - coin >= 0){
                int temp = fib(k-coin, coins) + 1;
                min_value = min(min_value, temp);
            }
        }
        return min_value;
    }
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int k, n, data;
        cin >> k;
        cin >> n;

        vector<int> coins;

        for(int i=0; i<n; i++){
            cin >> data;
            coins.push_back(data);
        }

        cout << fib(k, coins) << endl;
    }
}