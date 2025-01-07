#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct cmp{
    bool operator()(pair<int,int> a, pair<int,int> b){
        return a.first > b.first; // 반대로 작동
    }
};

int main(){
    int n, k;

    cin >> n >> k;

    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
    pq.push(make_pair(0, n));
    vector<int> visited(100001, 0);

    pair<int,int> data;
    while(!pq.empty()){
        data = pq.top(); pq.pop();
        int time = data.first;
        int x = data.second;

        visited[x] = 1;

        if(x == k){
            cout << time << endl;
            break;
        }
        if((x*2) <= 100000 && !visited[x*2]){
            pq.push(make_pair(time, x*2));
        }
        if((x+1) <= 100000 && !visited[x+1]){
            pq.push(make_pair(time+1, x+1));
        }
        if((x-1) >= 0 && !visited[x-1]){
            pq.push(make_pair(time+1, x-1));
        }
    }   
}