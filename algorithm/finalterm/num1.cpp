#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    return a.second < b.second;
}

int main(){
    // 회의실 배치
    int t;
    cin >> t;

    while(t--){
        int n, start, end;
        cin >> n;

        vector<pair<int,int>> v;

        for(int i=0; i<n; i++){
            cin >> start >> end;
            v.push_back(make_pair(start, end));
        }

        sort(v.begin(), v.end(), cmp);

        int count = 1;
        int endTime = v[0].second;

        for(int i=1; i<n; i++){
            if(v[i].first > endTime){
                count++;
                endTime = v[i].second;
            }
        }

        cout << count << endl;
    }
}