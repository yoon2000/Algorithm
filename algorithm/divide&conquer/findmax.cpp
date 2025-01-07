#include <iostream>
#include <vector>
using namespace std;

int find_max(vector<int> &a, int left, int right){
    if(left == right){
        return a[left];
    }

    int mid = (left + right) / 2;
    int left_max = find_max(a, left, mid);
    int right_max = find_max(a, mid+1, right);

    return max(left_max, right_max);
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

        int answer = find_max(a, 0, n-1);
        cout << answer << endl;
    }
}