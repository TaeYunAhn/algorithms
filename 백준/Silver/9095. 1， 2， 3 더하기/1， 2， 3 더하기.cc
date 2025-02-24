#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    cin >> T;
    
    int dp[11];
    //dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(int i = 4; i <= 11; i++){
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    vector<int> vec;
    while(T--){
        int n = 0;
        cin >> n;
        vec.push_back(n);
    }
    for(int i = 0; i < vec.size(); i++){
        cout << dp[vec[i]] << endl;
    }
    return 0;
}

/*
1 = 1가지
2 = 2가지
3 = 4가지
4 = 7가지
5 = 14가지
5가지 1개 1 1 1 1 1
4가지 4개 2 1 1 1 
3가지 3 1 1 => 3가지, 2 2 1 => 3가지
2가지 2개
1가지 1개

total : 14개

6 

7 = 44

10 = 274

결국 dp로 피보나치랑 같음
*/