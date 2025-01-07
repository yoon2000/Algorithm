#include <iostream>
#include <vector>
using namespace std;

int n;
int ans = -1;

void dfs(int a, int b, vector<int> v, int cnt){
    int dis = b-a;
    int q = dis / v[a-1];

    if(dis % v[a-1] == 0){
        ans = cnt + 1;
        return;
    }

    else{
        for(int i=1; i<= q; i++){
            dfs(a+(v[a-1]*i), b, v, cnt+1);
        }
    }
}

int main(){
    int data, a, b;
    cin >> n;

    vector<int> v;
    
    for(int i=0; i<n; i++){
        cin >> data;
        v.push_back(data);
    }

    cin >> a >> b;

    dfs(a, b, v, 0);

    cout << ans;
}