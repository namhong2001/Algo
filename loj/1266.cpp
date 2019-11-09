#include <iostream>
#include <vector>

using namespace std;

int N = 1001;
vector<vector<int>> bit;
int sum(int x, int y) {
    int ret = 0;
    for (int i=x; i>0; i -= i & -i) {
        for (int j=y; j>0; j -= j & -j) {
            ret += bit[i][j];
        }
    }
    return ret;
}
int sum(int x1, int y1, int x2, int y2) {
    return sum(x2, y2) - sum(x2, y1-1) - sum(x1-1, y2) + sum(x1-1, y1-1);
}
void add(int x, int y, int delta) {
    for (int i=x; i<=N; i += i & -i) {
        for (int j=y; j<=N; j += j & -j) {
            bit[i][j] += delta;
        }
    }
}
void update(int x, int y, int val) {
    add(x, y, val - sum(x, y, x, y));
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    for (int t=1; t<=T; ++t) {
        cout << "Case " << t << ":" << '\n';
        bit.assign(N+1, vector<int>(N+1, 0));
        int Q;
        cin >> Q;
        while (Q--) {
            int a;
            cin >> a;
            if (a == 0) {
                int x, y;
                cin >> x >> y;
                x++, y++;
                update(x, y, 1);
            } else if (a == 1) {
                int x1, y1, x2, y2;
                cin >> x1 >> y1 >> x2 >> y2;
                x1++, y1++, x2++, y2++;
                // cerr << "err " << sum(x2, y2) << endl;
                cout << sum(x1, y1, x2, y2) << '\n';
            }
        }
    }
    return 0;
}