#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

void dfs(vector<int> v, vector<int> curr, int sz, int idx){
    if(curr.size() == sz){
        for(auto i : curr){
            cout << i << " ";
        }
        cout << endl;
    }

    else{
        for(int i=idx; i<n; i++){
            vector<int> temp(curr);
            temp.push_back(v[i]);
            dfs(v, temp, sz, i);
        }
    }
}

int main(){
    int m, tmp;
    cin >> n >> m;

    vector<int> v;
    for(int i=0; i<n; i++){
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    vector<int> temp;
    for(int i=0; i<n; i++){
        temp.push_back(v[i]);
        dfs(v, temp, m, i);
        temp.clear();
    }
}