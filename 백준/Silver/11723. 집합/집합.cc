#include <iostream>
#include <cstring>
 
using namespace std;
 
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string simbol = "";
    int total_size = 0, simbol_num = 0;
    int arr[21] = {0};
    
    
    cin >> total_size;
    for(int i = 0; i<total_size; i++){
        cin >> simbol;
        
        if(simbol=="add"){
            cin >> simbol_num;
            if(arr[simbol_num]==0){   //없으면
                arr[simbol_num] = 1;
            }
        }
        
        else if(simbol=="remove"){
            cin >> simbol_num;
            if(arr[simbol_num] == 1){  //있으면
                arr[simbol_num] = 0;
            }
            
        }
        else if(simbol=="check"){
            cin >> simbol_num;
            if(arr[simbol_num] == 0){   //없으면
                cout << "0\n";
            } else{
                cout << "1\n";
            }
        }
        else if(simbol=="toggle"){
           cin >> simbol_num;
            if(arr[simbol_num] == 1){  //있으면
                arr[simbol_num] = 0;
            } else{
                arr[simbol_num] = 1;
            }
        }
        else if(simbol=="all"){
            
            for(int k = 1; k<=20; k++){ arr[k] = 1;}
            
        }
        else if(simbol=="empty"){
            memset(arr, 0, sizeof(arr));
        }
    }
    
    return 0;
}