#include<iostream>
#include<vector>
#include<queue>
#include<algorithm> 
using namespace std;

const int max_ = 200005;
vector<int> adj[max_];
int dist[max_];

pair<int, int> bfs(int start_node, int n) {
    for(int i = 1; i <= n; i++) dist[i] = -1;
    
    queue<int> q;
    q.push(start_node);
    dist[start_node] = 0;
    
    int farthest_node = start_node;
    int max_distance = 0;
    
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        if(dist[u] > max_distance) {
            max_distance = dist[u];
            farthest_node = u;
        }
        
        for(int v : adj[u]) {
            if(dist[v] == -1) { 
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    
    return {farthest_node, max_distance};
}

int main() {
    
    int n;
    if (!(cin >> n)) 
        return 0;

    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    pair<int, int> result1 = bfs(1, n);
    int PointA = result1.first;
    
    pair<int, int> result2 = bfs(PointA, n);
    int PointB = result2.first;
    int diameter_length = result2.second;
    
    cout << diameter_length << endl;
    cout << PointA << " " << PointB << endl;
    
    return 0;
}