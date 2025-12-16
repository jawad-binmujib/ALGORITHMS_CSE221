#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;


const long long inf = 1e18;


vector<long long> dijkstra(int nodes, int start, const vector<vector<pair<int, int>>>& adj_list){
    vector<long long> distance(nodes +1, inf);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    distance[start] = 0;
    pq.push({0, start});

    while(!pq.empty()){
        long long dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (dist > distance[u]){
            continue;
        }

        for (auto it : adj_list[u]){
            int weight = it.first;
            int v = it.second;
            
            if (distance[u]+ weight < distance[v]){
                distance[v] = distance[u] + weight;
                pq.push({distance[v], v});
            }
        }
      
    }
    return distance;

}

int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(nullptr);

    int nodes, edges, alice_start, bob_start;
    if (!(cin >> nodes >> edges >> alice_start >> bob_start)) return 0;
    
    vector<vector<pair<int, int>>> adj_list(nodes + 1);
    for (int i = 0; i < edges; i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj_list[u].push_back({w,v});
    }

    vector<long long> alice_dist = dijkstra(nodes, alice_start, adj_list);
    vector<long long> bob_dist = dijkstra(nodes, bob_start, adj_list);

    long long min_time = inf;
    int meeting_node = -1;
    for (int i = 1; i <= nodes; i++){
        if (alice_dist[i] != inf && bob_dist[i] != inf){
            long long meeting_time = max(alice_dist[i], bob_dist[i]);

            if (meeting_time < min_time){
                min_time = meeting_time;
                meeting_node =i;
            }
        }

    }   
    if (meeting_node == -1){
        cout << -1 << endl;
    }

    else{
        cout << min_time << " " << meeting_node << endl;

    }










}
