#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> players, int m, int k) {
    // 1. 각 시간대별로 필요한 서버(needed) 수 계산
    vector<int> needed(24, 0);
    for(int i = 0; i < 24; i++){
        if(players[i] >= m) {
            needed[i] = players[i] / m;  
            // C++ 정수 나눗셈 -> floor 연산과 동일
        } else {
            needed[i] = 0;
        }
    }

    // 2. active[i]: i시~i+1시 구간에 현재 가동 중인 서버 수
    vector<int> active(24, 0);
    int answer = 0;  // "서버 증설 횟수" 누적

    // 3. 0시부터 23시까지 순회하며 필요한 서버를 충족하도록 증설
    for(int i = 0; i < 24; i++){
        // 현재 가동 중인 서버 수가 필요한 서버 수보다 적으면 그 차이만큼 새로 증설
        if(active[i] < needed[i]){
            int toAdd = needed[i] - active[i]; 
            answer += toAdd;  // 서버 toAdd대를 "한 번에" 추가하면 증설 횟수도 toAdd만큼 증가

            // 새로 증설한 서버는 i시부터 i+k-1시까지 가동 (단, 최대 23시까지만)
            int endTime = min(i + k, 24);
            for(int t = i; t < endTime; t++){
                active[t] += toAdd;
            }
        }
    }

    return answer;
}
