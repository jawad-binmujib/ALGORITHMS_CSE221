#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int primsMST(int vertices, vector<vector<pair<int, int>>>& adj_list){


    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<bool> visited(vertices, false);
    int total_cost = 0;
    pq.push({0,0});
    while(!pq.empty()){
        int weight = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;

        visited[u] = true;
        total_cost += weight;

        for (auto it : adj_list[u]){
            int edge_weight = it.first;
            int adj_node = it.second;

            if (!visited[adj_node]){
                pq.push({edge_weight, adj_node});
            }
        }
    }


    return total_cost;
}

int main(){

    ios_base:: sync_with_stdio(false);
    cin.tie(nullptr);

    int vertices, edges;
    cin >> vertices >> edges;

    vector<vector<pair<int, int>>> adj_list(vertices);
    for (int i = 0; i < edges; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj_list[u].push_back({w, v});
        adj_list[v].push_back({w, u});
    }

    int result = primsMST(vertices, adj_list);

    cout <<"Minimum cost : " << result << endl;


    return 0;

}