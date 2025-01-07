#include <iostream>
#include <vector>
using namespace std;

int binary_search(vector<int> &v, int left, int right, int k){
    int mid = (left+right)/2;

    if(left > right){
        return -1; // not found
    }

    if(v[mid] == k){
        return mid;
    }
    else if(k > v[mid]) return binary_search(v, mid+1, right, k);
    else return binary_search(v, left, mid-1, k);
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int n, k, data;
        cin >> n >> k;

        vector<int> v;
        for(int i=0; i<n; i++){
            cin >> data;
            v.push_back(data);
        }

        cout << binary_search(v, 0, n-1, k) << endl;
    }
}