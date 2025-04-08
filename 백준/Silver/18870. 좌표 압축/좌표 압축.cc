#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N = 0;
    cin >> N;
    vector<int> arr(N);
    vector<int> sorted_arr;
    
    for(int i = 0; i < N; i++){
        cin >> arr[i];
        sorted_arr.push_back(arr[i]);
    }
    
    sort(sorted_arr.begin(), sorted_arr.end());
    sorted_arr.erase(unique(sorted_arr.begin(), sorted_arr.end()), sorted_arr.end());


    unordered_map<int, int> compress;
    for(int i = 0; i < sorted_arr.size(); i++){
        compress[sorted_arr[i]] = i;
    }
    
    for(int i = 0; i < N; i++){
        cout << compress[arr[i]] << " ";
    }
    
    return 0;
}