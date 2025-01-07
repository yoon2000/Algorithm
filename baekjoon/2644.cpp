#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int a, b, n, m;

vector<vector<int>> v(101);
int visited[101];

void dfs(){
    stack<pair<int,int>> st;
    st.push(make_pair(a, 0));
    visited[a] = 1;

    int depth = -1;
    pair<int,int> data;
    while(!st.empty()){
        data = st.top(); st.pop();
        for(auto i : v[data.first]){
            if(!visited[i]){
                visited[i] = 1;
                st.push(make_pair(i,data.second+1));

                if(i == b){
                    if(depth == -1) depth = data.second+1;
                    else depth = min(depth, data.second+1);
                }
            }
        }
    }
    cout << depth;
}

int main(){
    cin >> n;
    cin >> a >> b;
    cin >> m;

    // draw the graph
    int x,y;
    for(int i=0; i<m; i++){
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    dfs();

}