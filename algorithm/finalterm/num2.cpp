
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool hasCycle(vector<vector<int>>& graph, int n) {
    vector<int> indegree(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            indegree[graph[i][j]]++;
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    int cnt = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        cnt++;

        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i];
            indegree[next]--;
            if (indegree[next] == 0) {
                q.push(next);
            }
        }
    }

    return cnt != n;
}


int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> graph(n + 1);
        for (int i = 1; i <= n; i++) {
            int k, m;
            cin >> k >> m;
            for (int j = 0; j < m; j++) {
                int adj;
                cin >> adj;
                graph[k].push_back(adj);
                graph[adj].push_back(k);
            }
        }

        if (hasCycle(graph, n)) {
            cout << "1" << endl;
        } else {
            cout << "0" << endl;
        }
    }

    return 0;
}

