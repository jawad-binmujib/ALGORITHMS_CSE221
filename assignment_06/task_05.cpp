#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int max_num = 200005;

vector<int> adj[max_num];
int dist[max_num];

int main() {

    int n, m, s, q_queries;
    if (!(cin >> n >> m >> s >> q_queries))
        return 0;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }


    for (int i = 1; i <= n; i++) {
        dist[i] = -1;
    }

    queue<int> q;
    for (int i = 0; i < s; i++) {
        int source_node;
        cin >> source_node;
        
     
        q.push(source_node);
        dist[source_node] = 0; 
    }

   
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (dist[v] == -1) { 
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

  
    for (int i = 0; i < q_queries; i++) {
        int destination_node;
        cin >> destination_node;
        cout << dist[destination_node] << " ";
    }
    
    cout << endl;

    return 0;
}