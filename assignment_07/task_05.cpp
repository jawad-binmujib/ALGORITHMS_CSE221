#include<iostream>
#include<vector>
#include<queue>
#include<tuple> 
using namespace std;

const long long inf = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    vector<int> U(M), V(M), W(M);
    for (int i = 0; i < M; i++) cin >> U[i];
    for (int i = 0; i < M; i++) cin >> V[i];
    for (int i = 0; i < M; i++) cin >> W[i];

    vector<vector<pair<int, int>>> adj_list(N + 1);
    for (int i = 0; i < M; i++) {
        adj_list[U[i]].push_back({W[i], V[i]});
    }

    vector<vector<long long>> distance(N + 1, vector<long long>(2, inf));
    priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> pq;
    distance[1][0] = 0;
    distance[1][1] = 0;
    pq.push({0, 1, 0});
    pq.push({0, 1, 1});

    while (!pq.empty()) {
        auto [d, u, p] = pq.top(); 
        pq.pop();

        if (d > distance[u][p]) continue;

        for (auto edge : adj_list[u]) {
            int weight = edge.first;
            int v = edge.second;
            int edge_parity = weight % 2; 

            if (p != edge_parity) {
                if (distance[u][p] + weight < distance[v][edge_parity]) {
                    distance[v][edge_parity] = distance[u][p] + weight;
                    pq.push({distance[v][edge_parity], v, edge_parity});
                }
            }
        }
    }

    long long ans = min(distance[N][0], distance[N][1]);

    if (ans == inf) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}