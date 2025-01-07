#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int mcss(vector<int> &a, int left, int right){
    if(left == right){
        return a[left];
    }

    int mid = (left + right) / 2;
    int left_max = mcss(a, left, mid);
    int right_max = mcss(a, mid+1, right);

    int tmp = 0;
    int left_part = INT_MIN;
    for(int i=mid; i>=left; i--){
        left_part = max(left_part, tmp += a[i]);
    }

    tmp = 0;
    int right_part = INT_MIN;
    for(int i=mid+1; i<=right; i++){
        right_part = max(right_part, tmp += a[i]);
    }

    int mid_max = left_part + right_part;
    return max(max(left_max, right_max), mid_max);
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> a;
        int data;
        for(int i=0; i<n; i++){
            cin >> data;
            a.push_back(data);
        }

        int answer = mcss(a, 0, n-1);

        if(answer <= 0) answer = 0;
        
        cout << answer << endl;

    }
}
