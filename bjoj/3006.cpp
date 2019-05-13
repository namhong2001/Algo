#include <bits/stdc++.h>

using namespace std;

struct Fenwick {
    vector<int> arr;
    Fenwick(const int n): arr(n+1) {}

    void add(int p, int v) {
        while (p<arr.size()) {
            arr[p] += v;
            p += p & -p;
        }
    }
    int sum(int p) {
        int ret = 0;
        while(p>0) {
            ret += arr[p];
            p &= p-1;
        }
        return ret;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> pos(n+1);
    Fenwick fw(n);
    for (int i=1; i<=n; ++i) {
        int a;
        cin >> a;
        pos[a] = i;
        fw.add(a, 1);
    }
    for (int i=1; i<=n; ++i) {
        if (i%2) {
            cout << fw.sum(pos[i/2+1]-1) << '\n';
            fw.add(pos[i/2+1], -1);
        } else {
            cout << n-i+1-fw.sum(pos[n-i/2+1]) << '\n';
            fw.add(pos[n-i/2+1], -1);
        }
    }
    return 0;
}


