#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    for (int t=1; t<=T; ++t) {
        int n, s;
        cin >> n >> s;
        vector<int> trinkets(n);
        for (int i=0; i<n; ++i) {
            cin >> trinkets[i];
        }
        vector<vector<int>> ans(n, vector<int>(n, 0));
        for (int i=0; i<n; ++i) ans[i][i] = 1;
        int max_ans = 1;
        for (int i=0; i<n; ++i) {
            unordered_map<int,int> m;
            m[trinkets[i]]++;
            for (int j=i+1; j<n; ++j) {
                m[trinkets[j]]++;
                if (m[trinkets[j]] <= s) {
                    ans[i][j] = ans[i][j-1]+1;
                } else if (m[trinkets[j]] == s+1) {
                    ans[i][j] = ans[i][j-1] - s;
                } else {
                    ans[i][j] = ans[i][j-1];
                }
                max_ans = max(max_ans, ans[i][j]);
            }
        }
        cout << "Case #" << t << ": " << max_ans << '\n';
    }


    return 0;
}
