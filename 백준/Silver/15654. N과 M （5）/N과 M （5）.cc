#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(vector<int> &number, vector<int> &sequence, vector<bool> &visited, int M)
{
    if (sequence.size() == M) {
        for (int num : sequence) {
            cout << num << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < number.size(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            sequence.push_back(number[i]);
            dfs(number, sequence, visited, M);
            sequence.pop_back();
            visited[i] = false;
        }
    }
}

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> number;
    vector<int> sequence;
    vector<bool> visited;

    for (int i = 0; i < N; i++) {
        int temp = 0;
        cin >> temp;
        number.push_back(temp);
    }
    sort(number.begin(), number.end());

    visited.resize(N, false);

    dfs(number, sequence, visited, M);

    return 0;
}
