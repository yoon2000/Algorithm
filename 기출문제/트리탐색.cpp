#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct node
{
    int data;
    int left_idx;
    int right_idx;
    node(int a, int left = -1, int right = -1):data(a), left_idx(left), right_idx(right){}
};

void in_order_helper(vector<node> tree, node root){
    if(root.left_idx != -1){
        in_order_helper(tree, tree[root.left_idx]);
    }
    if(root.right_idx != -1){
        in_order_helper(tree, tree[root.right_idx]);
    }
    cout << root.data << " ";
}

void in_order(vector<node> tree, node root){
    in_order_helper(tree, root);
    cout << endl;
}



int main(){
    int t;
    cin >> t;
    
    while(t--){
        int n, data;
        cin >> n;

        vector<node> tree(n, node(0));

        for(int i=0; i<n; i++){
            cin >> data;
            if(i==0){
                tree[0].data= data;
            }
            else{
                tree[i].data = data;

                if(i%2){ // 홀수
                    tree[i-1].left_idx = i;
                }
                else{   // 짝수
                    tree[i-2].right_idx = i;
                }
            }
        }

        // in-order
        node root = tree[0];
        in_order(tree, root);        

        // pre-order
        for(auto i : tree){
            cout << i.data << " ";
        }
        cout << endl;

        // post-order

    }
}