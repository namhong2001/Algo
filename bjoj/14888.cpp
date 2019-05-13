#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    int nums[n];
    for (int i=0; i<n; ++i) {
        cin >> nums[i];
    }
    vector<int> opers;
    for (int i=0; i<4; ++i) {
        int cnt;
        cin >> cnt;
        for (int j=0; j<cnt; ++j) {
            opers.push_back(i);
        }
    }
    int max_score = -1e9-1;
    int min_score = 1e9+1;

    do {
        int score = nums[0];
        for (int i=1; i<n; ++i) {
            if (opers[i-1] == 0) {
                score += nums[i];
            } else if (opers[i-1] == 1) {
                score -= nums[i];
            } else if (opers[i-1] == 2) {
                score *= nums[i];
            } else if (opers[i-1] == 3) {
                score /= nums[i];
            }
        }
        max_score = max(max_score, score);
        min_score = min(min_score, score);
    } while(next_permutation(opers.begin(), opers.end()));
    cout << max_score << '\n' << min_score;
    return 0;
}
