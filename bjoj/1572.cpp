#include <bits/stdc++.h>

using namespace std;

const int NUM_MAX = 65536;

struct Fenwick {
    vector<int> arr;
    Fenwick(const int n): arr(n+1) {}

    void add(int p, int v) {
        ++p;
        while(p<arr.size()) {
            arr[p] += v;
            p += p & -p;
        }
    }
    int sum(int p) {
        ++p;
        int ret = 0;
        while (p>0) {
            ret += arr[p];
            p &= p-1;
        }
        return ret;
    }
};

int bs(int l, int r, int idx, Fenwick& fw) {
    if (l == r) return l;
    int m = (l+r)/2;
    int ls = fw.sum(m) - fw.sum(l-1);
    if (ls >= idx) return bs(l, m, idx, fw);
    return bs(m+1, r, idx - ls, fw);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> tick(n);
    long long ans = 0;
    Fenwick fw(NUM_MAX+1);
    for (int i=0; i<n; ++i) {
        cin >> tick[i];
        fw.add(tick[i], 1);
        if (i < k-1) continue;
        if (i > k-1) {
            fw.add(tick[i-k], -1);
        }
        ans += bs(0, NUM_MAX, (k+1)/2, fw);
    }
    cout << ans;
    return 0;
}
