#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    int N = 0;
    cin >> N;
    while (N--){
        int x = 0;
        cin >> x;
        if(x > 0){
            minHeap.push(x);
        }
        else if (x == 0){
            if(!minHeap.empty()){
                cout << minHeap.top()<<"\n";
                minHeap.pop();
            }
            else
                cout<< "0\n";
        }
    }
    return 0;
}