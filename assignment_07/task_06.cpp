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

    vector<vector<pair<int, int>>> adj_list(N + 1);
    for (int i = 0; i < M; i++) {
        
        int u, v, w;
        cin >> u >> v >> w;
        adj_list[u].push_back({w, v});
        adj_list[v].push_back({w, u});

    }


    vector<vector<long long>> distance(N + 1, vector<long long>(2, inf));
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    distance[S][0] = 0;
    pq.push({0, S});

    while (!pq.empty()) {
        long long d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > distance[u][1]) continue;

        for (auto it : adj_list[u]) {
            
            int weight = it.first;
            int v = it.second;
            long long new_distance = d + weight;

            if (new_distance < distance[v][0]) {
                distance[v][1] = distance[v][0];
                pq.push({distance[v][1], v}); 
                distance[v][0] = new_distance;
                pq.push({distance[v][0], v});
            }

            else if (new_distance > distance[v][0] && new_distance < distance[v][1]) {
                distance[v][1] = new_distance;
                pq.push({distance[v][1], v});
            }
        }
    }


    if (distance[D][1] == inf){
        cout << -1 << endl;
    }

    else 
        cout << distance[D][1] << endl;

    return 0;
    
}