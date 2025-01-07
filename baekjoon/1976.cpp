#include <iostream>
#include <vector>
using namespace std;
#define MAX_INT 201

int parent[MAX_INT];

int find(int a);
void merge(int a, int b);
bool in_same_set(int a, int b);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, data;
    cin >> n >> m;

    for(int i=1; i<n+1; i++){
        parent[i] = i;
    }

    for(int i=1; i<n+1; i++){
        for(int j=1; j<n+1; j++){
            cin >> data;
            if(data){
                merge(i,j);
            }
        }
    }

    vector<int> city_plan;
    for(int i=0; i<m; i++){
        cin >> data;
        city_plan.push_back(data);
    }

    bool check_plan = true;
    int root = find(city_plan[0]);
    for(int i=1; i<m; i++){
        if(root != find(city_plan[i])){
            check_plan = false;
        }
    }

    if(check_plan){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}

int find(int a){
    while(a != parent[a]){
        a = parent[a];
    }
    return a;
}

void merge(int a, int b){
    int root_a = find(a);
    int root_b = find(b);

    parent[root_a] = root_b;
}

bool in_same_set(int a, int b){
    a = find(a);
    b = find(b);

    return a == b;
}