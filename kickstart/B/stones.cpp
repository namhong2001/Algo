#include <iostream>
#include <vector>


using namespace std;

struct V {
    int s, e, l;
};

int main() {
    int T;
    cin >> T;
    for (int t=1; t<=T; ++t) {
        int n;
        vector<V> vs;
        for (int i=0; i<n; ++i) {
            int s, e, l;
            cin >> s >> e >> l;
            vs.push_back({s, e, l});
        }
        vector<vector<int>> s_sum(n, vector<int>(n, 0));
        vector<vector<int>> e_sum(n, vector<int>(n, 0));
        vector<vector<int>> l_sum(n, vector<int>(n, 0));
        vector<vector<int>> d(n, vector<int>(d, 0));
        for (int k=0; k<n; ++k) {
            for (int i=0; i<n; ++i) {
                for (int j=0; j<n; ++j) {
                    int nd = d[i][k] + d[k][j];
                    d[i][j] = max(d[i][j], )

                }
            }
        }


        cout << "Case #" << t << ": " << ans << '\n';
    }


    return 0;
}
