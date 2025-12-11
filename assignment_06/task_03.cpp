#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int max_num = 2005;
int dist[max_num][max_num];
int dx[] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int dy[] = { -1, 1, -2, 2, -2, 2, -1, 1 };

int main() {
 
    int n;
    if (!(cin >> n)) 
        return 0;

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j] = -1;
        }
    }

    queue<pair<int, int>> q;
    q.push({x1, y1});
    dist[x1][y1] = 0; 

    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();
        
        int cx = current.first;
        int cy = current.second;

        if (cx == x2 && cy == y2) {
            cout << dist[cx][cy] << endl;
            return 0;
        }

        for (int i = 0; i < 8; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[cx][cy] + 1;
                q.push({nx, ny});
            }
        }
    }

    cout << dist[x2][y2] << endl;

    return 0;
}