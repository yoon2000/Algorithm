#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> temp;

// 번호가 작은게 항상 위에 존재하지는 않음

struct node
{
   int parent;
   vector<int> childs;

   node(int a):parent(a),childs(temp){}

    bool is_leaf(){
        if(childs.size() == 0) return true;
        else return false;
    }
};

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, del_idx, data;
        cin >> n >> del_idx;

        vector<node> nodes(n, node(0));
        for(int i=0; i<n; i++){
            cin >> data;
            if(data == -1){
                nodes[0].parent = -1;
            }
            else{
                nodes[i].parent = data;
                if(i != del_idx){
                    nodes[data].childs.push_back(i);
                }
            }
        }


        int root = 0;
        int leaf_cnt = 0;

        // preorder?
        queue<int> q;
        if(root != del_idx){
            q.push(root);
        }
        
        while(!q.empty()){
            data = q.front(); q.pop();
            if(nodes[data].is_leaf()) leaf_cnt++;
            else{
                for(auto i : nodes[data].childs){
                q.push(i);
                }
            }
        }
        
        cout << leaf_cnt << endl;
    }
    
}