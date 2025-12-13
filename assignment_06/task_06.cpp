#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int max_num = 300005;

vector<int> adj[max_num];
int dist[max_num];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, s, q_queries;
    
    if (cin >> n >> m >> s >> q_queries) {

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u); 
        }

        for (int i = 1; i <= n; i++) {
            dist[i] = -1;
        }

        queue<int> que;
        for (int i = 0; i < s; i++) {
            int source_node;
            cin >> source_node;

            dist[source_node] = 0;
            que.push(source_node);
        }


        while (!que.empty()) {
            int u = que.front();
            que.pop();

            for (int v : adj[u]) {
                if (dist[v] == -1) { 
                    dist[v] = dist[u] + 1;
                    que.push(v);
                }
            }
        }

        for (int i = 0; i < q_queries; i++) {
            int dest_node;
            cin >> dest_node;
            cout << dist[dest_node] << " ";
        }
        cout << endl;
    }

    return 0;
}