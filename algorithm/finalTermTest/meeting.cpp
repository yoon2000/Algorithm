#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main(){
    int n, start, end;
    cin >> n;

    vector<pair<int,int>> time_table;
    for(int i=0; i<n; i++){
        cin >> start >> end;
        time_table.push_back(make_pair(start, end));
    }

    sort(time_table.begin(), time_table.end(), cmp);
    
    int curr_end = time_table[0].second, answer = 1;
    
    for(int i=1; i<n; i++){
        if(time_table[i].first >= curr_end){
            curr_end = time_table[i].second;
            answer++;
        }
    }

    cout << answer << endl;
}