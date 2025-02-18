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
    
    int total_num;
    vector<int> vec;
    cin >> total_num;
    for(int i = 0; i < total_num; i++){
        int num = 0;
        cin >> num;
        vec.push_back(num);
    }
    sort(vec.begin(), vec.end());
    int answer = 0;
    for(int i = 0; i < total_num; i++){
        for(int j = 0; j <= i; j++){
            answer += vec[j];
        }
    }
    cout << answer<<endl;
    
    
}