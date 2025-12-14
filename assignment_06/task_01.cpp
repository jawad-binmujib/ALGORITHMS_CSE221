#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int max_number = 200005;
vector<int> adj[max_number];      
int in_degree[max_number];        
vector<int> result;
int main(){
    int course, prereq;
    cin >> course >> prereq;

    for (int i = 0; i < prereq; i++){

        int u,v;
        cin >> u >> v;
        adj[u].push_back(v); 
        in_degree[v]++;
    }
    queue<int> q;
    for (int i= 1; i <= course; i++){
        if (in_degree[i] == 0)  
            q.push(i);
    

    }

    while (!q.empty()){
        int node = q.front();
        q.pop();
        result.push_back(node);

        for (int v : adj[node]) {
            in_degree[v]--;
            if (in_degree[v] == 0) q.push(v);
        }

    }

    if (result.size() < course) {
        cout << -1 << endl;
    } 
    else {
        for (int i = 0; i < course; i++) {
            cout << result[i] << (i == course - 1 ? "" : " ");
        }
        cout << endl;
    }

    return 0;
}
