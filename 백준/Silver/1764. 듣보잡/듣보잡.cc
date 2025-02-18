
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
    
    map<string, int> is_duplicated;
    vector<string> sorting_result;
    
    int N = 0, M = 0;
    cin >> N >> M;
    for (int i = 0; i < N + M; i++){
        string input_str;
        cin >> input_str;
        is_duplicated[input_str]++;
        if(is_duplicated[input_str] > 1)
            sorting_result.push_back(input_str);
    }
    sort(sorting_result.begin(), sorting_result.end());
    
    cout << sorting_result.size() << endl;
    for (auto e : sorting_result)
        cout << e << endl;
    
}