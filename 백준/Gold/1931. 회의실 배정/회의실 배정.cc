#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;



int main()
{
    int n = 0;
    
    cin >> n;
    vector<pair<int,int>> arr;
    
    for(int i = 0; i < n; i++){
        int c = 0, r = 0;
        cin >> c >> r;
        arr.push_back({r,c});
    }
    
    sort(arr.begin(), arr.end());
    //unique(arr.firtst().begin(), arr.second().begin());
    
    int count = 0;
int endTime = 0;

for (int i = 0; i < arr.size(); i++) {
    if (arr[i].second >= endTime) {
        count++;
        endTime = arr[i].first;
    }
}
    cout << count;
    return 0;
}