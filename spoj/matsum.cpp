#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<vector<int>> arr(N+1, vector<int>(N+1, 0));
        vector<vector<int>> bit(N+1, vector<int>(N+1, 0));
        auto add = [&](int x, int y, int delta) {
            for (int i=x; i<=N; i += i & -i) {
                for (int j=y; j<=N; j += j & -j) {
                    bit[i][j] += delta;
                }
            }
        };
        auto _sum = [&](int x, int y) {
            int ret = 0;
            for (int i=x; i>0; i -= i & -i) {
                for (int j=y; j>0; j -= j & -j) {
                    ret += bit[i][j];
                }
            }
            return ret;
        };
        auto sum = [&](int x1, int y1, int x2, int y2) {
            return _sum(x2, y2) - _sum(x1-1, y2) - _sum(x2, y1-1) + _sum(x1-1, y1-1);
        };
        auto update = [&](int x, int y, int n) {
            int delta = n - arr[x][y];
            add(x, y, delta);
            arr[x][y] = n;
        };
        while (true) {
            string s;
            cin >> s;
            if (s == "END") break;
            else if (s == "SET") {
                int x, y, n;
                cin >> x >> y >> n;
                update(x+1, y+1, n);
            } else if (s == "SUM") {
                int x1, y1, x2, y2;
                cin >> x1 >> y1 >> x2 >> y2;
                cout << sum(x1+1, y1+1, x2+1, y2+1) << '\n';
            }
        }
    }
    return 0;
}