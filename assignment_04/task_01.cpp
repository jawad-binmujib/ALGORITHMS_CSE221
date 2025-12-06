#include<iostream>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    int arr1[101][101] = {0};

    for (int i =0; i < m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        arr1[u][v] = w;
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j ++ ){
            cout << arr1[i][j] << " ";
        
        }

        cout << endl;
    }
    return 0;

}