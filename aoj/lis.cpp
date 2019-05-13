#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N_MAX = 500;
int nums[N_MAX];

int solve(int n) {
    vector<int> max_len(n, 1);
    int ans = 0;
    for (int i=0; i<n; ++i) {
        for (int j=i+1; j<n; ++j) {
            if (nums[j] > nums[i]) {
                max_len[j] = max(max_len[j], max_len[i]+1);
                ans = max(ans, max_len[j]);
            }
        }
    }
    return ans;
}

int main() {
    int c;
    cin >> c;
    while(c--) {
        int n;
        cin >> n;
        for (int i=0; i<n; ++i) {
            cin >> nums[i];
        }
        cout << solve(n) << endl;
    }

    return 0;
}
