#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    
    // N = 2인 경우 조건을 만족하는 순열은 없다.
    if(N == 2){
        cout << "NO\n";
        return 0;
    }
    
    cout << "YES\n";
    
    if(N == 1){
        cout << "1\n";
        return 0;
    }
    
    // N >= 3인 경우: 구성 알고리즘에 따라 1, 3, 2, 4, 5, ... , N 출력
    vector<int> perm;
    perm.push_back(1);
    perm.push_back(3);
    perm.push_back(2);
    for (int i = 4; i <= N; i++){
        perm.push_back(i);
    }
    
    // 출력: 공백으로 구분하여 순열 출력
    for (int num : perm) {
        cout << num << " ";
    }
    cout << "\n";
    
    return 0;
}
