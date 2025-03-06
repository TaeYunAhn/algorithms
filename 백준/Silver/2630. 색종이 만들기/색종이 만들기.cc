#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int white = 0, blue = 0;
vector<vector<int>> paper;


void check_paper(int x, int y, int size){
    int firstColor = paper[x][y];
    bool isSame = true;
    
    for(int i = x; i < x + size; i++){
        for(int j = y; j < y + size; j++){
            if(paper[i][j] != firstColor){
                isSame = false;
                break;
            }
        }
        if(!isSame)
            break;
    }
    if(isSame){
        if(firstColor == 0)
            white++;
        else
            blue++;
        return ;
    }
    
    int newSize = size / 2;
    check_paper(x, y, newSize);
    check_paper(x + newSize, y, newSize);
    check_paper(x, y + newSize, newSize);
    check_paper(x + newSize, y + newSize, newSize);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N = 0;
    cin >> N;
    paper.assign(N, vector<int>(N));
    for(int i = 0; i<N;i++){
        for(int j=0; j<N; j++){
            cin >> paper[i][j];
        }
    }
    check_paper(0,0,N);
    
    cout << white << "\n" << blue << "\n";
    return 0;
}