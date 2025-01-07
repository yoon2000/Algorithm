#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>
using namespace std;

int main(){
    int a, k;
    cin >> a >> k;

    int answer = INT_MAX;

    vector<int> visited(k+1, 0);
    pair<int,int> data = make_pair(a, 0);
    queue<pair<int,int>> q;
    q.push(data);

    while(!q.empty()){
        data = q.front(); q.pop();

        if(data.second >= answer){
            continue;
        }
        
        int x = data.first + 1;
        int y = data.first * 2;

        if(x == k || y == k){
            answer = min(answer, data.second+1);
        }
        if(x < k && !visited[x]){
            visited[x] = 1;
            q.push(make_pair(x, data.second+1));
        }
        if(y < k && !visited[y]){
            visited[y] = 1;
            q.push(make_pair(y, data.second+1));
        }
    }

    cout << answer << endl;

    return 0;
}