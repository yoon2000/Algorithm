#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_INT 1001
using namespace std;

vector<int> visited(MAX_INT, 0);

void dfs(int node, vector<vector<int>>& graph, int& componentSize) {
    visited[node] = 1;
    componentSize++;
    for (int adjacent : graph[node]) {
        if (!visited[adjacent]) {
            dfs(adjacent, graph, componentSize);
        }
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k, m, data;
        cin >> n;

        vector<vector<int>> graph(n + 1);
        for (int i = 0; i < n; i++) {
            visited[i] = 0;
            cin >> k >> m;
            for (int j = 0; j < m; j++) {
                cin >> data;
                graph[k].push_back(data);
            }
        }
        visited[n] = 0;

        vector<int> answer;
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                int componentSize = 0;
                dfs(i, graph, componentSize);
                answer.push_back(componentSize);
            }
        }

        cout << answer.size();
        sort(answer.begin(), answer.end());
        for (auto i : answer) {
            cout << " " << i;
        }
        cout << endl;
    }
}
