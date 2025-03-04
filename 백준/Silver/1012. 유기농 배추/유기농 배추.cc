#include <iostream>
#include <vector>

using namespace std;


void dfs(int i, int j, vector<vector<int>> &field, 
                vector<vector<bool>> &visited, int M, int N){
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    visited[i][j] = true;
    
    for(int d = 0; d < 4; d++){
        int ni = i + dx[d];
        int nj = j + dy[d];
        
        if(ni >= 0 && ni < M && nj >= 0 && nj < N && !visited[ni][nj] && field[ni][nj] == 1){
            dfs(ni, nj, field, visited, M, N);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int T = 0, M = 0, N = 0, K = 0;
    cin >> T;
    while (T--){
        cin >> M >> N >> K;
        vector<vector<int>> field(M, vector<int>(N, 0));
        vector<vector<bool>> visited(M, vector<bool>(N, false));
    
        for(int i = 0; i < K; i++){
            int x, y;
            cin >> x >> y;
            field[x][y] = 1;
        }
        
        int count = 0;
        
        for(int i = 0; i < M; i++){
            for (int j = 0; j < N; j++) {
                if(field[i][j] == 1 && !visited[i][j]){
                    dfs(i, j, field, visited, M, N);
                    count++;
                }
            }
        }
    
        cout << count << endl;
    }
    
    return 0;
}