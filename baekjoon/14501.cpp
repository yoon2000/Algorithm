#include <iostream>
#include <vector>
using namespace std;


int n, answer;
vector<pair<int,int>> v;

// dfs
void dfs(int day, int sum){
    if(day == n + 1){
        if(answer < sum){
            answer = sum;
        }
        return;
    }
    if(day > n + 1) return;
    dfs(day + 1, sum);
    dfs(day + v[day-1].first, sum + v[day-1].second);
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    int time, pay;
    for(int i=0; i<n; i++){
        cin >> time >> pay;
        v.push_back(make_pair(time, pay));
    }

    dfs(1, 0);
    cout << answer << endl;
}