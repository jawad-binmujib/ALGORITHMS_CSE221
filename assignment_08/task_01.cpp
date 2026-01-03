#include <iostream>
#include <vector>

using namespace std;

const int max_num = 300005;
int parent[max_num];
int sz[max_num]; 


int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}


int union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    
    if (a != b) {
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        return sz[a]; 
    }
    return sz[a]; 
}

void solve() {
    int n, k;
    if (!(cin >> n >> k)) return;

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }

    for (int i = 0; i < k; i++) {
        int u, v;
        cin >> u >> v;
        cout << union_sets(u, v) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}