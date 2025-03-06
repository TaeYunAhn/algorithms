#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N = 0, M = 0;
    cin >> N >> M;
    vector<int>tree(N);
    for(int i = 0; i < N; i++){
        cin >> tree[i];
    }
    
    
    int low = 0, high = *max_element(tree.begin(), tree.end());
    int answer = 0;
    
    while(low <= high){
        int mid = (high + low) / 2;
        long long total = 0;
        for(int i = 0; i < N; i++){
            if(tree[i] > mid)
                total += (tree[i] - mid);
        }
        if(total >= M){
            answer = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    cout << answer<<"\n";
    
    return 0;
}