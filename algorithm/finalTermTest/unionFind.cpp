#include <iostream>
using namespace std;

int parent[1000001];

int find(int u) {
    while (u != parent[u]) {
        u = parent[u];
    }
    return u;
}

void merge(int u, int v){
    u = find(u);
    v = find(v);
    if(u == v) return;
    parent[u] = v;
}

bool is_same_set(int u, int v){
    u = find(u);
    v = find(v);
    return u == v;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    int a, b, c;
    cin >> n >> m;

    for(int i=0; i <= n; i++){
        parent[i] = i;
    }

    for(int i=0; i<m; i++){
        cin >> a >> b >> c;
        if(a == 0) merge(b, c);
        else{
            if(is_same_set(b,c)){
                cout << "YES\n";
            }
            else{
                cout << "NO\n";
            }
        }
    }
}