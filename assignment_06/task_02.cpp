#include<iostream>
#include<vector>
#include<algorithm> 

using namespace std;
const int max_num = 200005; 
vector<int>adj[max_num];
bool visited_array[max_num];
int color[max_num];

int counter1 = 0;
int counter2 = 0;

void dfs(int u, int c) {
    visited_array[u] = true;
    color[u] = c;
    if (c == 0) {
        counter1++;
    }
    else {
        counter2++;
    }

    for (int v : adj[u]) {
        if (!visited_array[v]) {
            dfs(v, 1 - c);
        }
    }
}

int main() {

    int n, m;
    if (!(cin >> n >> m)){ 
        return 0;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    long long total_max_players = 0;

    for (int i = 1; i <= n; i++) {
        if (!visited_array[i]) {
            counter1 = 0;
            counter2 = 0;
            dfs(i, 0);
            
       
        total_max_players += max(counter1, counter2);
        }
    }

    cout << total_max_players << endl;

    return 0;
}