#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int dfs(vector<vector<int>>& g, int v, vector<bool>& visited, int p) {
    vector<int>& adj = g[v];
    visited[v] = true;
    int count = 1;

    for (int u : adj) {
        if (u == p) continue;
        if (!visited[u]) {
            count += dfs(g, u, visited, p);
        }
    }

    return count;
}

bool isArticulationPoint(vector<vector<int>>& g, int v, int n) {
    vector<bool> visited(n + 1, false);
    int count = dfs(g, (v == 1) ? 2 : 1, visited, v);

    return count == n - 1;
}

vector<int> findArticulationPoints(vector<vector<int>>& g, int n) {
    vector<int> points;
    for (int v = 1; v <= n; ++v) {
        if (!isArticulationPoint(g, v, n)) {
            points.push_back(v);
        }
    }

    return points;
}

void dfsBCC(int v, int p, vector<int>& stack, vector<int>& low, vector<int>& disc, vector<set<int>>& components, vector<vector<int>>& g) {
    static int time = 0;
    int children = 0;
    disc[v] = low[v] = ++time;
    stack.push_back(v);

    for (int u : g[v]) {
        if (u == p) continue;
        if (disc[u] == -1) {
            children++;
            dfsBCC(u, v, stack, low, disc, components, g);
            low[v] = min(low[v], low[u]);

            if (low[u] >= disc[v]) {
                set<int> component;
                while (stack.back() != u) {
                    component.insert(stack.back());
                    stack.pop_back();
                }
                component.insert(stack.back());
                stack.pop_back();
                components.push_back(component);
            }
        } else if (disc[u] < low[v]) {
            low[v] = disc[u];
        }
    }

    if (p == -1 && children > 1) {
        set<int> component;
        while (!stack.empty()) {
            component.insert(stack.back());
            stack.pop_back();
        }
        components.push_back(component);
    }
}

vector<set<int>> findBiConnectedComponents(vector<vector<int>>& g, vector<int>& points) {
    vector<set<int>> components;
    vector<int> visited(g.size() + 1, 0);
    vector<int> stack;
    vector<int> low(g.size() + 1, -1);
    vector<int> disc(g.size() + 1, -1);

    for (int point : points) {
        if (visited[point] == 0) {
            dfsBCC(point, -1, stack, low, disc, components, g);
        }
    }

    return components;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> g(n + 1);

        for (int i = 0; i < n; i++) {
            int node, m;
            cin >> node >> m;
            for (int j = 0; j < m; j++) {
                int adjacent;
                cin >> adjacent;
                g[node].push_back(adjacent);
            }
        }

        vector<int> points = findArticulationPoints(g, n);

        int bcc = findBiConnectedComponents(g, points).size() - 1;
        if (bcc == -1) {
            bcc = 1;
        }
        cout << bcc << endl;
        cout << points.size() << " ";
        for (int point : points) {
            cout << point << " ";
        }
        cout << endl;
    }

    return 0;
}
