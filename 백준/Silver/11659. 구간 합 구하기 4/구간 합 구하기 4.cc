#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N_size, M_size;
    cin >> N_size >> M_size;
    
    vector<int> N(N_size);
    for (int i = 0; i < N_size; i++){
        cin >> N[i];
    }
    
    vector<long long> prefix(N_size + 1, 0);
    for (int i = 1; i <= N_size; i++){
        prefix[i] = prefix[i-1] + N[i-1];
    }
    
    for (int i = 0; i < M_size; i++){
        int L, R;
        cin >> L >> R;
        cout << prefix[R] - prefix[L-1] << "\n";
    }
    
    return 0;
}
