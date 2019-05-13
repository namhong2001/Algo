#include <bits/stdc++.h>

using namespace std;

const int N_MAX = 100001;

int fenwickIndex[N_MAX];

struct Fenwick {
    vector<int> arr;

    Fenwick(int n): arr(n+1) {}

    int sum(int p) {
        int ret = 0;
        while(p>0) {
            ret += arr[p];
            p &= p-1;
        }
        return ret;
    }

    void add(int p, int v) {
        while (p<arr.size()) {
            arr[p] += v;
            p += p & -p;
        }
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int c;
    cin >> c;
    while (c--) {
        int n, m;
        cin >> n >> m;
        Fenwick fw(n+m);
        for (int i=1; i<=n; ++i) {
            fenwickIndex[n-i+1] = i;
            fw.add(i, 1);
        }
        for (int i=1; i<=m; ++i) {
            int a;
            cin >> a;
            int oldIndex = fenwickIndex[a];
            cout << fw.sum(n+i-1)-fw.sum(oldIndex) << ' ';
            fw.add(oldIndex, -1);
            int newIndex = fenwickIndex[a] = n+i;
            fw.add(newIndex, 1);
        }
        cout << '\n';
    }
    return 0;
}
