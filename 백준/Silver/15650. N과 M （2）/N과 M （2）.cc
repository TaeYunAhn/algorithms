#include <iostream>
#include <vector>

using namespace std; 

int n = 0, m = 0;
vector<int> result;
void dfs(int start, int depth) {
    if (depth == m) {
        for(int num : result){
            cout << num << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = start; i <= n; i++) {
        result.push_back(i);
        dfs(i + 1, depth + 1);
        result.pop_back();
    }
}


int main()
{
    cin >> n >> m;
    
    dfs(1, 0);
    return 0;
}