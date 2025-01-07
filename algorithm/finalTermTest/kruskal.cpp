#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX_INT 1001

int parent[MAX_INT];
int sz[MAX_INT];

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

int find(int i){
    while(i != parent[i]){
        i = parent[i];
    }
    return i;
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return;

    if(sz[a] > sz[b]){
        parent[b] = a;
        sz[a] += sz[b];
    }
    else{
        parent[a] = b;
        sz[b] += sz[a];
    }
}

bool inSameSet(int a, int b){
    a = find(a);
    b = find(b);
    return a == b;
}

void kruskal(priority_queue<edge, vector<edge>, cmp> pq, int n){
    vector<edge> v;

    while(v.size() < n-1){
        edge curr_edge = pq.top(); pq.pop();
        if(inSameSet(curr_edge.start, curr_edge.end)) continue;

        v.push_back(curr_edge);
        merge(curr_edge.start, curr_edge.end);
    }

    int sumOfWeight = 0;
    for(edge i : v){
        sumOfWeight += i.weight;
    }

    cout << sumOfWeight << endl;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int n, k, m, node_num, weight;
        cin >> n;

        priority_queue<edge, vector<edge>, cmp> pq;

        for(int i=1; i<=n; i++){
            parent[i] = i;
            sz[i] = 1;

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

        kruskal(pq, n);
    }
}