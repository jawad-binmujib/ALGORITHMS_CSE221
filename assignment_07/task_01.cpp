#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

const long long inf = 1e18; 
long long dijkstra(int nodes, int sources, int destinations, const vector<vector<pair<int, int>>>& adj_list, vector<int>& parent) {
    
    vector<long long> distance(nodes + 1, inf);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    distance[sources] = 0;
    pq.push({0, sources});

    while (!pq.empty()) {
        long long dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();


        if (dist > distance[u]) 
            continue;

        for (auto it : adj_list[u]) {
            int weight = it.first;
            int v = it.second;

            if (distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                parent[v] = u; 
                pq.push({distance[v], v});
            }
        }
    }

    return distance[destinations];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int nodes, M, sources, destinations;
    if (!(cin >> nodes >> M >> sources >> destinations)) 
        return 0;

    vector<int> U(M), V(M), W(M);
    for (int i = 0; i < M; i++) cin >> U[i];
    for (int i = 0; i < M; i++) cin >> V[i];
    for (int i = 0; i < M; i++) cin >> W[i];

    vector<vector<pair<int, int>>> adj_list(nodes + 1);
    for (int i = 0; i < M; i++) {
        adj_list[U[i]].push_back({W[i], V[i]});
    }

    vector<int> parent(nodes + 1, -1);
    long long result = dijkstra(nodes, sources, destinations, adj_list, parent);

    if (result == inf) {
        cout << -1 << endl;
    } 
    else {
        cout << result << endl;
        
        vector<int> path;
        for (int v = destinations; v != -1; v = parent[v]) {
            path.push_back(v);
        }
        reverse(path.begin(), path.end());

        for (int i = 0; i < path.size(); i++) {
            cout << path[i] << (i == path.size() - 1 ? "" : " ");
        }
        cout << endl;
    }

    return 0;
}