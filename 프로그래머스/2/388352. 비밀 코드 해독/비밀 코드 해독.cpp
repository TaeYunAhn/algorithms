#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    int count = 0;

    vector<int> numbers;
    for (int i = 1; i <= n; ++i) {
        numbers.push_back(i);
    }

    vector<bool> select(n, false);
    // 5개를 고르기 위해 마지막 5개를 true로 세팅
    fill(select.end() - 5, select.end(), true);

    do {
        vector<int> candidate;
        for (int i = 0; i < n; ++i) {
            if (select[i]) {
                candidate.push_back(numbers[i]);
            }
        }

        bool valid = true;
        for (int i = 0; i < q.size(); ++i) {
            int match = 0;
            int p1 = 0, p2 = 0;
            while (p1 < 5 && p2 < 5) {
                if (candidate[p1] < q[i][p2]) {
                    ++p1;
                } else if (candidate[p1] > q[i][p2]) {
                    ++p2;
                } else {
                    ++match;
                    ++p1;
                    ++p2;
                }
            }
            if (match != ans[i]) {
                valid = false;
                break;
            }
        }

        if (valid) {
            ++count;
        }

    } while (next_permutation(select.begin(), select.end()));

    return count;
}

// example usage
int main() {
    int n = 10;
    vector<vector<int>> q = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {3, 7, 8, 9, 10}, {2, 5, 7, 9, 10}, {3, 4, 5, 6, 7}};
    vector<int> ans = {2, 3, 4, 3, 3};

    cout << solution(n, q, ans) << endl; // output: 3

    return 0;
}