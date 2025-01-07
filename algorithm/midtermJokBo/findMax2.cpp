#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

pair<int,int> findMax(vector<int> v, int left, int right){
    if(left == right) return make_pair(v[left], INT_MIN);

    int mid = (left+right) / 2;

    pair<int,int> left_p = findMax(v, left, mid);
    pair<int,int> right_p = findMax(v, mid+1, right);

    pair<int,int> ret_p;

    vector<int> temp;
    temp.push_back(left_p.first); temp.push_back(right_p.first);
    temp.push_back(left_p.second); temp.push_back(right_p.second);

    sort(temp.begin(), temp.end());
    
    int t_sz = temp.size();
    ret_p.first = temp[t_sz -1];
    ret_p.second = temp[t_sz - 2];

    return ret_p;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int n, data;
        cin >> n;

        vector<int> v;
        for(int i=0; i<n; i++){
            cin >> data;
            v.push_back(data);
        }

        pair<int,int> answer = findMax(v, 0, n-1);

        cout << answer.second << endl;

    }
}