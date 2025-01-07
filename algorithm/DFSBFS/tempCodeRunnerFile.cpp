#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>
#define MAX_SIZE 101
using namespace std;

int back[MAX_SIZE];
int dfsNumber[MAX_SIZE];
int g_num;
vector<int> a;
int result;
void dfs(int x, bool isRoot, vector<vector<int>> v){
    bool isArti = false;
    int node = 0;
    for(int i=0;i<v[x].size();i++){
        if(dfsNumber[v[x][i]] != -1){
            back[x] = min(back[x], dfsNumber[v[x][i]]);
        } 
        else{
            node++;
            dfsNumber[v[x][i]] = g_num++;
            dfs(v[x][i], false, v);
            if(back[v[x][i]] >= dfsNumber[x]){
                isArti = true;
                result++;
            }
            else{
                back[x] = min(back[x], back[v[x][i]]);
            }
        }
        
    }
    if(isArti && ((isRoot && node>=2) || !isRoot)){
        a.push_back(x);
    }
}

int main(){
    int k;
    cin>>k;
    while(k--){
        a.clear();
        memset(dfsNumber, -1, sizeof(dfsNumber));
        memset(back, -1, sizeof(back));
        g_num = 1;
        result=0;
        int n;
        cin>>n;
        vector<vector<int>> v(MAX_SIZE);
        for(int j=1;j<=n;j++){
            int from, to, size;
            cin>>from>>size;
            back[from] = from;
            for(int i=1;i<=size;i++){
                cin>>to;
                v[from].push_back(to);
            }
        }
        
        for(int i=1;i<=n;i++){
            if(dfsNumber[i] != -1) continue;
            dfsNumber[i] = g_num++;
            dfs(i, true, v);
        }
        cout<<result<<"\n";
        sort(a.begin(), a.end());
        cout<<a.size()<<" ";
        for(int i=0;i<a.size();i++){
            cout<<a[i]<<" ";
        }
        cout<<"\n";
    }
}
