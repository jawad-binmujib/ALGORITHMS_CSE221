#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const long long inf = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, S, D;
    if (!(cin >> N >> M >> S >> D)) return 0;
    
    vector<long long> node_weights(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> node_weights[i];
    }

    vector<vector<int>> adj(N + 1);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }


    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    vector<long long> distance(N + 1, inf);
    distance[S] = node_weights[S];
    pq.push({distance[S], S});

    while (!pq.empty()) {
        long long d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > distance[u]) continue;

        for (int v : adj[u]) {
            long long new_weight = d + node_weights[v];

            if (new_weight < distance[v]) {
                distance[v] = new_weight;
                pq.push({distance[v], v});
            }
        }
    }


    
    if (distance[D] == inf) {
        cout << -1 << endl;
    } else {
        cout << distance[D] << endl;
    }

    return 0;
}