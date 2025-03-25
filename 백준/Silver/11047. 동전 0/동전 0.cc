
#include <iostream>
using namespace std;

int main()
{
    int n = 0, m = 0, count = 0;
    cin >> n >> m;
    int arr[n] = {0};
    
    for(int i = 0; i < n; i++){
        int temp = 0;
        cin >> temp;
        arr[i] = temp;
    }
    
    for(int i = n - 1; i >= 0; i--){
        if(arr[i] <= m){
            count+= m / arr[i];
            m %= arr[i];
        }
        else if(m == 0)
            break;
    }
    
    cout << count;
    

    return 0;
}