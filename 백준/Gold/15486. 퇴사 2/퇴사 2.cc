#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    int T[N];
    int P[N];
    for (int i = 0; i < N; i++) {
        cin >> T[i] >> P[i];
    }

    long long dp [N + 2] = {0};

    for (int i = 0; i < N; i++) {
        dp[i + 1] = max(dp[i + 1], dp[i]);
        if (i + T[i] <= N) {
            dp[i + T[i]] = max(dp[i + T[i]], dp[i] + P[i]);
        }
    }

    cout << *max_element(dp, dp + N + 1) << endl;

    return 0;
}
