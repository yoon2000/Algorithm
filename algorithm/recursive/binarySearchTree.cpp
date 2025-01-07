#include <iostream>
using namespace std;

struct node
{
    int data; // 노드에 저장되는 정수 데이터
    struct node* left; // 왼쪽 서브트리
    struct node* right; // 오른쪽 서브트리
};

void insert(struct node **root, int data);
void preOrder(struct node *root);
void inOrder(struct node *root);
void postOrder(struct node *root);
int size(struct node *root);
int height(struct node *root);
int sumOfWeight(struct node *root);
int maxPathWeight(struct node *root);
void mirror(struct node **root);
void destruct(struct node **root);

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        struct node* root = nullptr;
        cin >> n;

        for(int i=0; i<n; i++){
            int data;
            cin >> data;

            insert(&root, data);
        }

        cout << size(root) << endl;
        cout << height(root) - 1 << endl;
        cout << sumOfWeight(root) << endl;
        cout << maxPathWeight(root) << endl;

        mirror(&root);

        preOrder(root);
        cout << "\n";
        inOrder(root);
        cout << "\n";
        postOrder(root);
        cout << "\n";

        destruct(&root);
        if (root == NULL)
        {
            cout << "0\n";
        }
        else
        {
            cout << "1\n";
        }
    }
    return 0;
}

// 데이터 삽입(recursion)
void insert(struct node** root, int data)
{
    if (*root == nullptr) {
        *root = new struct node;
        (*root)->data = data;
        (*root)->left = nullptr;
        (*root)->right = nullptr;
        return;
    }
    if (data < (*root)->data) {
        insert(&((*root)->left), data); // 왼쪽 서브트리로 이동
    } 
    else {
        insert(&((*root)->right), data); // 오른쪽 서브트리로 이동
    }
}
// 전위(preorder)탐색(recursion)
void preOrder(struct node* root)
{
    if(root == nullptr){
        return;
    }
    else{
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
// 중위(inorder)탐색(recursion)
void inOrder(struct node* root)
{
    if(root == nullptr){
        return;
    }
    else{
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}
// 후위(postorder)탐색(recursion)
void postOrder(struct node* root)
{
    if(root == nullptr){
        return;
    }
    else{
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}
// 노드의 개수(recursion)
int size(struct node* root)
{
    if(root == nullptr){
        return 0;
    }
    else{
        return size(root->left) + size(root->right) + 1;
    }
}
// 높이(recursion)
int height(struct node* root)
{
    if(root == nullptr){
        return 0;
    }
    else{
        int left_height = height(root->left);
        int right_height = height(root->right);

        return 1 + max(left_height, right_height);
    }
}
// 미러 이미지로 변환하기(recursion)
void mirror(struct node** root)
{
    if ((*root) == nullptr) {
        return;  // 노드가 없을 때 함수 종료
    }

    mirror(&((*root)->left));
    mirror(&((*root)->right));

    struct node* temp = (*root)->left;
    (*root)->left = (*root)->right;
    (*root)->right = temp;

}
// 노드에 저장된 데이터의 값의 합 구하기(recursion)
int sumOfWeight(struct node* root)
{
    if(root == nullptr){
        return 0;
    }
    else{
        return sumOfWeight(root->left) + sumOfWeight(root->right) + root->data ;
    }
}
// 루트노드부터 단말노드까지의 경로 상의 데이터의 최대합(recusrion)
int maxPathWeight(struct node* root)
{
    if(root == nullptr){
        return 0;
    }
    else{
        int left_max = maxPathWeight(root->left);
        int right_max = maxPathWeight(root->right);

        return max(left_max, right_max) + root->data;
    }
}
// 트리노드의 동적 메모리 해제하기(recursion)
void destruct(struct node** root)
{
    if((*root)->left != nullptr){
        destruct(&((*root)->left));
    }
    if((*root)->right != nullptr){
        destruct(&((*root)->right));
    }
    if(*root != nullptr){
        delete *root;
        *root = nullptr;
    }
}



