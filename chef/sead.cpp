#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int NMAX = 1e5+1;
int st[NMAX][26];

int main() {
    int N, M;
    cin >> N;
    vector<int> arr(N);
    for (int i=0; i<N; ++i) cin >> arr[i];
    for (int i=1; i<=N-1; ++i) {
        st[i][0] = arr[i] - arr[i-1];
    }
    for (int j=1; j<26; ++j) {
        for (int i=1; i+(1<<j)<=N; ++i) {
            st[i][j] = max(st[i][j-1], st[i+(1<<(j-1))][j-1]);
        }
    }
    auto get_max = [&](int s, int e) {
        int r = e-s+1;
        int ret = st[s][0];
        for (int j=0; j<26; ++j) {
            if (r & (1<<j)) {
                ret = max(ret, st[s][j]);
                s += 1<<j;
            }
        }
        return ret;
    };
    auto decision = [&](int l, int r, int D) {
        if (l == r) return true;
        return get_max(l+1, r) <= D;
    };
    cin >> M;
    while (M--) {
        int T, D;
        cin >> T >> D;
        auto upper = upper_bound(arr.begin(), arr.end(), T);
        int r = distance(arr.begin(), prev(upper)); // true
        int l = -1; // false
        while (l+1 < r) {
            int mid = (l+r)/2;
            if (decision(mid, r, D)) r = mid;
            else l = mid;
        }
        cout << r+1 << '\n';
    }
    return 0;
}