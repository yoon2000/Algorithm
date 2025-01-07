#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int MAX = 1000; // 최대 정점 수

vector<int> graph[MAX]; // 그래프
bool visited[MAX];      // 방문 여부
int dfsNum[MAX];        // 정점의 DFS 번호
int back[MAX];          // 정점에서 갈 수 있는 가장 낮은 DFS 번호
int dfsCounter;         // DFS 번호 카운터
int numComponents;      // 양절 그래프의 수

stack<pair<int, int>> st; // DFS 스택

// 양절점 찾는 함수
void findArticulationPoints(int u, int parent) {
    visited[u] = true;
    dfsNum[u] = back[u] = ++dfsCounter;

    for (int v : graph[u]) {
        if (!visited[v]) {
            st.push({u, v}); // 간선(u, v)를 스택에 추가

            findArticulationPoints(v, u);

            back[u] = min(back[u], back[v]);

            if (dfsNum[u] <= back[v]) {
                cout << "양절점: " << u << endl;
                
                // 양절 그래프 출력
                while (!st.empty()) {
                    int x = st.top().first;
                    int y = st.top().second;
                    st.pop();
                    
                    cout << x << " - " << y << " ";
                    
                    if (x == u && y == v) break;
                }
                cout << endl;
            }
        } else if (v != parent) {
            back[u] = min(back[u], dfsNum[v]);
            st.push({u, v});
        }
    }
}

int main() {
    int n, m; // 정점 수, 간선 수
    cin >> m >> n;

    // 그래프 입력
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // 초기화
    fill(visited, visited + n, false);
    dfsCounter = 0;
    numComponents = 0;

    // 양절점 찾기
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            findArticulationPoints(i, -1); // 시작 정점과 부모(-1) 전달
        }
    }

    return 0;
}
