#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

const long long inf = 1e18;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    vector<vector<pair<int, int>>> adj_list(N + 1);
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj_list[u].push_back({w, v});
        adj_list[v].push_back({w, u});
    }

    vector<long long> max_danger(N + 1, inf);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    max_danger[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        long long current_danger = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (current_danger > max_danger[u]) continue;

        for (auto it : adj_list[u]) {
            int weight = it.first;
            int v = it.second;
            long long new_danger = max(max_danger[u], (long long)weight);

            if (new_danger < max_danger[v]) {
                max_danger[v] = new_danger;
                pq.push({max_danger[v], v});
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        if (max_danger[i] == inf) {
            cout << -1 << (i == N ? "" : " ");
        } else {
            cout << max_danger[i] << (i == N ? "" : " ");
        }
    }
    cout << endl;

    return 0;
}