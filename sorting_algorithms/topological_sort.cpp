#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void kahnsAlgorithm(int vertices, vector<vector<int>>& adj) {
    vector<int> inDegree(vertices, 0);
    for (int u = 0; u < vertices; u++) {
        for (int v : adj[u]){
            inDegree[v]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < vertices; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }


    vector<int> topoResult;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topoResult.push_back(node);

        for (int neighbor : adj[node]) {
            inDegree[neighbor]--;

            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    if (topoResult.size()!= vertices) {
        cout << "Topological Sort not possible (Cycle detected!)" << endl;
    } 
    else {
        cout << "Topological Sort Order: ";
        for (int task : topoResult) {
            cout << task << " ";
        }
        cout << endl;
    }
}

int main() {
    int V = 6;
    vector<vector<int>> adj(V);
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    cout << "Running Kahn's Algorithm..." << endl;
    kahnsAlgorithm(V, adj);

    return 0;
}