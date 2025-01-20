#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    long long n, score, p, data;
    cin >> n >> score >> p;

    vector<int> v;
    for(int i=0; i<n; i++){
        cin >> data;
        v.push_back(data);
    }

    int rank = 1;
    int cnt = 0;
    for(int i=0; i<n; i++){
        if(score < v[i]) rank++;
        else if(score == v[i]) rank = rank;
        else break;
        cnt++;
    }

    if(cnt == p) rank = -1;
    if(n == 0) rank = 1;

    cout << rank << endl;

}