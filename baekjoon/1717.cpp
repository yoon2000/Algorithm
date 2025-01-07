#include <iostream>
using namespace std;

int p[1000001];
int tree_rank[1000001]; // 각 집합의 Rank (트리의 높이)를 저장하는 배열

int find(int a) {
    if (p[a] == a) return a;
    else return p[a] = find(p[a]); // 경로 압축 적용
}

bool is_same_set(int a, int b) {
    return find(a) == find(b);
}

void merge(int a, int b) {
    int pa = find(a);
    int pb = find(b);

    if (pa != pb) { // 두 집합이 다른 경우에만 합침
        // Rank를 사용하여 더 작은 트리를 더 큰 트리에 붙임
        if (tree_rank[pa] < tree_rank[pb]) {
            p[pa] = pb;
        } else if (tree_rank[pa] > tree_rank[pb]) {
            p[pb] = pa;
        } else {
            p[pa] = pb;
            tree_rank[pb]++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, a, b, c;
    cin >> n >> m;

    for (int i = 0; i <= n; i++) {
        p[i] = i;
        tree_rank[i] = 1; // 초기 Rank를 1로 설정
    }

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;

        if (a) {
            if (is_same_set(b, c)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        } else {
            merge(b, c);
        }
    }

    return 0;
}
