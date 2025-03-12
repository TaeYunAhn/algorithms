#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int N, K;
    queue<pair<int, int>> q;
    int spot[100001] = {0};
    bool visited[100001] = {false};
    int result[100001] = {0};
    cin >> N >> K;

    q.push(pair<int, int>(N, 0));
    while (!q.empty())
    {
        int now = q.front().first, cnt = q.front().second;
        q.pop();
        if (!visited[now] && (now >= 0 && now < 100001))
        {
            visited[now] = true;
            if (result[now] == 0)
            {
                result[now] = cnt;
            }
            cnt++;
            q.push(pair<int, int>(now - 1, cnt));
            q.push(pair<int, int>(now + 1, cnt));
            q.push(pair<int, int>(now * 2, cnt));
        }
    }

    cout << result[K];

    return 0;
}