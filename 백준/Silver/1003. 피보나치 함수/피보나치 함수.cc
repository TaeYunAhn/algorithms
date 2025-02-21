#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    cin >> T;
    
    int dp[41][2];
    dp[0][0] = 1;
    dp[0][1] = 0;
    dp[1][0] = 0;
    dp[1][1] = 1;
    
    for(int i = 2; i <= 40; i++){
        dp[i][0] = dp[i-1][0] + dp[i-2][0];
        dp[i][1] = dp[i-1][1] + dp[i-2][1];
    }
    vector<int> vec;
    
    while(T--){
        
        int n;
        cin >> n;
        vec.push_back(n);
    }
    
    for(int i = 0; i < vec.size(); i++){
        cout << dp[vec[i]][0] << " " << dp[vec[i]][1] << endl;
    }
    return 0;
    
}