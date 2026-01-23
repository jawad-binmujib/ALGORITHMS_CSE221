#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct Edge {
    int u, v, w, id;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

const int max_num = 1005;
int parent[max_num];
vector<pair<int, int>> adj[max_num]; 

int find_set(int v) {
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    parent[find_set(b)] = find_set(a);
}


bool get_path(int u, int target, int p, vector<int>& path_weights) {
    if (u == target) return true;
    for (auto& edge : adj[u]) {
        int v = edge.first;
        int w = edge.second;
        if (v != p) {
            path_weights.push_back(w);
            if (get_path(v, target, u, path_weights)) return true;
            path_weights.pop_back();
        }
    }
    return false;
}

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    vector<Edge> edges;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w, i});
    }

    sort(edges.begin(), edges.end());

    for (int i = 1; i <= n; i++) parent[i] = i;
    for (int i = 1; i <= n; i++) adj[i].clear();

    long long mst_cost = 0;
    vector<bool> in_mst(m, false);
    int edges_count = 0;


    for (int i = 0; i < m; i++) {
        if (find_set(edges[i].u) != find_set(edges[i].v)) {
            union_sets(edges[i].u, edges[i].v);
            mst_cost += edges[i].w;
            in_mst[i] = true;
            edges_count++;
            adj[edges[i].u].push_back({edges[i].v, edges[i].w});
            adj[edges[i].v].push_back({edges[i].u, edges[i].w});
        }
    }

    if (edges_count < n - 1) {
        cout << -1 << endl;
        return;
    }

    long long second_best = LLONG_MAX;
    bool found = false;

    for (int i = 0; i < m; i++) {
        if (!in_mst[i]) {
            int u = edges[i].u;
            int v = edges[i].v;
            int w_new = edges[i].w;

            vector<int> path_weights;
            get_path(u, v, -1, path_weights);


            for (int w_old : path_weights) {
                long long new_cost = mst_cost + w_new - w_old;
                if (new_cost > mst_cost) {
                    if (new_cost < second_best) {
                        second_best = new_cost;
                        found = true;
                    }
                }
            }
        }
    }

    if (found) cout << second_best << endl;
    else cout << -1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}