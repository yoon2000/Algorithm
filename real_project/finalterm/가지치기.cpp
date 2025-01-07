#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node
{
    int id;
    node* left = nullptr;
    node* right = nullptr;

    bool is_leaf(){
        if(left == nullptr && right == nullptr) return true;
        return false;
    }
    node(int a) : id(a){}
};


int main(){
    int t;
    cin >> t;

    while(t--){
        int n, r_node;
        cin >> n >> r_node;

        vector<node> v(n, node(0));

        int data, root;
        for(int i=0; i<n; i++){
            cin >> data;
            v[i].id = i;

            if(data == -1) root = i;
            else{
                if(v[data].left == nullptr){
                    v[data].left = &v[i];
                }
                else{
                    v[data].right = &v[i];
                }
            }
        }

        vector<int> visited(n, 0);
        queue<node> q;
        q.push(v[root]);
        visited[root] = 1;
        node data;
        while(!q.empty()){

        }        
    }
}