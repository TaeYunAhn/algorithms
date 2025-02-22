#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    int dp[1000001]; // N이 최대 10^6이므로
    dp[1] = 0;
    
    for (int i = 2; i <= N; i++){
        dp[i] = dp[i - 1] + 1; // 1을 빼는 경우
        if (i % 2 == 0)
            dp[i] = min(dp[i], dp[i / 2] + 1);
        if (i % 3 == 0)
            dp[i] = min(dp[i], dp[i / 3] + 1);
    }
    
    cout << dp[N] << "\n";
    return 0;
}
