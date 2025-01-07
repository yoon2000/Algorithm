#include <iostream>
#include <limits.h>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n, s, temp;

    cin >> n >> s;

    vector<int> v;

    for(int i=0; i<n; i++){
        cin >> temp;
        v.push_back(temp);
    }

    int left = 0;
    int right = 0;
    int answer = INT_MAX;
    int sum = 0;

    while(left <= n){

        if(sum >= s){
            answer = min(answer, right - left);
            sum -= v[left++];
        }
        else if(right == n){
            break;
        }
        else{
            sum += v[right++];
        }
    }

    if(answer == INT_MAX) cout << 0 << endl;
    else cout << answer << endl;
}