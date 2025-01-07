if (*root == nullptr) {
        return;
    }

    destruct(&((*root)->left));  // 왼쪽 서브트리 삭제
    destruct(&((*root)->right)); // 오른쪽 서브트리 삭제

    delete *root; // 현재 노드 삭제
    *root = nullptr;