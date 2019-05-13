#include <iostream>
#include <cstring>

using namespace std;

const int N_MAX = 1025;

struct Fenwick {
    int arr[N_MAX][N_MAX];
    int n;
    Fenwick(const int& n): n(n) {
        memset(arr, 0, sizeof(arr));
    }

    void add(int x, int y, int val) {
        for (int i=x; i<=n; i += i & -i) {
            for (int j=y; j<=n; j += j & -j) {
                arr[i][j] += val;
            }
        }
    }

    int sum(int x, int y) {
        int ret = 0;
        for (int i=x; i>0; i &= i-1) {
            for (int j=y; j>0; j &= j-1) {
                ret += arr[i][j];
            }
        }
        return ret;
    }

    void change(int x, int y, int val) {
        long long originVal = (long long)sum(x,y)-sum(x-1, y)-sum(x,y-1)+sum(x-1,y-1);
        add(x, y, val-originVal);
    }
};




int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int n, m;
    cin >> n >> m;
    Fenwick fenwick(n);
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=n; ++j) {
            int a;
            cin >> a;
            fenwick.add(i, j, a);
        }
    }

    for (int i=0; i<m; ++i) {
        int w;
        cin >> w;
        if (w == 0) {
            int x, y, c;
            cin >> x >> y >> c;
            fenwick.change(x, y, c);
        } else if (w == 1) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            long long sum = 0;
            sum += fenwick.sum(max(x1, x2), max(y1, y2));
            sum -= fenwick.sum(min(x1, x2)-1, max(y1, y2));
            sum -= fenwick.sum(max(x1, x2), min(y1, y2)-1);
            sum += fenwick.sum(min(x1, x2)-1, min(y1, y2)-1);
            cout << sum << '\n';
        }
    }

    return 0;
}
