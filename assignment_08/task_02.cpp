#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

const int max_num = 200005;
int parent[max_num];

int find_set(int v) {
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) parent[b] = a;
}

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    sort(edges.begin(), edges.end());

    for (int i = 1; i <= n; i++) parent[i] = i;

    long long mst_cost = 0;
    int edges_count = 0;

    for (const auto& edge : edges) {
        if (find_set(edge.u) != find_set(edge.v)) {
            mst_cost += edge.w;
            union_sets(edge.u, edge.v);
            edges_count++;
        }
    }

    if (edges_count == n - 1)
        cout << mst_cost << endl;
    else
        cout << -1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}