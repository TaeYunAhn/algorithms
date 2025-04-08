#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int dx[4] = {1, -1, 0, 0};  // 아래, 위, 오른쪽, 왼쪽
    int dy[4] = {0, 0, 1, -1};

    int n = 0, m = 0;
    cin >> n >> m;
    vector<vector<int>> map(n, vector<int>(m));       // 입력 지도
    vector<vector<int>> dist(n, vector<int>(m, -1));   // 거리 저장 (초기값 -1)
    vector<vector<bool>> visited(n, vector<bool>(m)); // 방문 여부
    
    queue<pair<int,int>>q;
    
    int start_x = -1, start_y = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 2) {
                start_x = i;
                start_y = j;
            }
        }
    }

    q.push({start_x, start_y});
    visited[start_x][start_y] = true;
    dist[start_x][start_y] = 0;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 범위 벗어나면 continue
            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
               continue;

            // 벽이거나 이미 방문했으면 건너뜀
            if (map[nx][ny] == 0 || visited[nx][ny])
                continue;

            visited[nx][ny] = true;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 0)
               cout << 0 << " ";
            else
                cout << dist[i][j] << " ";
        }
        cout << "\n";
    }

    
    
    return 0;
}