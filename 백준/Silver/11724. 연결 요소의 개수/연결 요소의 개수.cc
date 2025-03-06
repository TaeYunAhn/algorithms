#include <iostream>
#include <vector>

using namespace std;

void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited) {
    visited[node] = true;
    for (int next : graph[node]) {
        if (!visited[next]) {
            dfs(next, graph, visited);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph(N + 1);
    vector<bool> visited(N + 1, false);
    
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    int count = 0;
    for(int i = 1; i <= N; i++){
        if(!visited[i]){
            dfs(i, graph, visited);
            count++;
        }
    }
    cout << count << "\n";
    return 0;
}