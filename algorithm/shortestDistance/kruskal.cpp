#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <limits.h>
using namespace std;

struct edge{
    int start;
    int end;
    int weight;
};

struct cmp{
    bool operator()(edge a, edge b){
        return a.weight > b.weight;
    }
};

int find(int parent[], int i) {
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

void unionSet(int parent[], int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}

bool isCycle(int parent[], int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    if (xset != yset)
        return false;
    return true;
}

void kruskal(int start, int n, priority_queue<edge, vector<edge>, cmp>& pq){ // 참조로 수정
    vector<edge> result;
    int parent[n+1];
    for(int i=1; i<n+1; i++){
        parent[i] = -1;
    }

    int sumOfWeight = 0;

    while(result.size() < n-1){
        edge curr_edge = pq.top();
        pq.pop();

        if(isCycle(parent, curr_edge.start, curr_edge.end)) continue;

        result.push_back(curr_edge);
        sumOfWeight += curr_edge.weight;

        unionSet(parent, curr_edge.start, curr_edge.end);
    }

    // 최소 신장 트리의 간선 출력
    // for (const auto& e : result) {
    //     cout << e.start << " " << e.end << " " << e.weight << endl;
    // }

    cout << sumOfWeight << endl;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int n, k, m, node_num, weight;
        cin >> n;

        priority_queue<edge, vector<edge>, cmp> pq;
        for(int i=1; i<n+1; i++){
            cin >> k >> m;
            for(int j=0; j<m; j++){
                cin >> node_num >> weight;

                edge temp;
                temp.start = k;
                temp.end = node_num;
                temp.weight = weight;

                pq.push(temp);
            }
        } 

        kruskal(1, n, pq);
    }
}
