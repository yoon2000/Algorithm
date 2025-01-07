#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<vector<int>> adj;
vector<int> low, disc;
vector<bool> visited, isArticulation;
stack<pair<int, int>> st;
int ta = 0;

void dfs(int u, int parent) {
    disc[u] = low[u] = ++ta;
    visited[u] = true;
    int children = 0;

    for (int v : adj[u]) {
        if (v == parent)
            continue;

        if (!visited[v]) {
            st.push({u, v});
            children++;
            dfs(v, u);

            low[u] = min(low[u], low[v]);

            if ((parent == -1 && children > 1) || (parent != -1 && low[v] >= disc[u])) {
                isArticulation[u] = true;

                vector<pair<int, int>> bcc;
                while (st.top() != make_pair(u, v)) {
                    bcc.push_back(st.top());
                    st.pop();
                }
                bcc.push_back(st.top());
                st.pop();

                // Process the biconnected component
                cout << "Biconnected Component: ";
                for (auto edge : bcc) {
                    cout << edge.first << "-" << edge.second << " ";
                }
                cout << endl;
            }
        } else if (disc[v] < disc[u]) {
            st.push({u, v});
            low[u] = min(low[u], disc[v]);
        }
    }
}

void findBiconnectedComponents(int n) {
    low.resize(n + 1);
    disc.resize(n + 1);
    visited.resize(n + 1);
    isArticulation.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i, -1);
        }
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        adj.clear();
        adj.resize(n + 1);

        for (int i = 1; i <= n; i++) {
            int k, m;
            cin >> k >> m;

            for (int j = 0; j < m; j++) {
                int v;
                cin >> v;
                adj[k].push_back(v);
            }
        }

        findBiconnectedComponents(n);
    }

    return 0;
}
