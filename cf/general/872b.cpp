#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> arr(N);
    for (int i=0; i<N; ++i) cin >> arr[i];
    vector<vector<int>> minst(N, vector<int>(26));
    vector<vector<int>> maxst(N, vector<int>(26));
    for (int i=0; i<N; ++i) {
        minst[i][0] = arr[i];
        maxst[i][0] = arr[i];
    }
    for (int j=1; j<26; ++j) {
        for (int i=0; i+(1<<j)<=N; ++i) {
            minst[i][j] = min(minst[i][j-1], minst[i+(1<<(j-1))][j-1]);
            maxst[i][j] = max(maxst[i][j-1], maxst[i+(1<<(j-1))][j-1]);
        }
    }
    auto getmin = [&](int s, int e) {
        int r = e-s+1;
        int ret = arr[s];
        for (int j=0; j<26; ++j) {
            if (r & (1<<j)) {
                ret = min(ret, minst[s][j]);
                s += 1<<j;
            }
        }
        return ret;
    };
    auto getmax = [&](int s, int e) {
        int r = e-s+1;
        int ret = arr[s];
        for (int j=0; j<26; ++j) {
            if (r & (1<<j)) {
                ret = max(ret, maxst[s][j]);
                s += 1<<j;
            }
        }
        return ret;
    };
    if (K == 1) {
        cout << getmin(0, N-1);
    } else if (K == 2) {
        int ans = arr[0];
        for (int e=0; e<N-1; ++e) {
            ans = max({ans, getmin(0, e), getmin(e+1, N-1)});
        }
        cout << ans;
    } else {
        cout << *max_element(arr.begin(), arr.end());
    }
    return 0;
}
