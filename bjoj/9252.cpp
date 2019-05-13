#include <iostream>
#include <algorithm>

using namespace std;
const int len_max = 1000;
int dp[len_max][len_max];

int main() {
    string a, b;
    cin >> a >> b;
    int max_i = 0, max_j = 0, max_seq = 0;
    for (int i=0; i<a.size(); ++i) {
        for (int j=0; j<b.size(); ++j) {
            if (a[i] == b[j]) {
                if (i>0 && j>0) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = 1;
                }
                if (dp[i][j] > max_seq) {
                    max_seq = dp[i][j];
                    max_i = i;
                    max_j = j;
                }
            } else {
                int top = i>0 ? dp[i-1][j] : 0;
                int left = j>0 ? dp[i][j-1] : 0;
                dp[i][j] = max(top, left);
            }

        }
    }
    cout << max_seq << '\n';
    string lcs;
    int remain = max_seq;
    int i = max_i;
    int j = max_j;
    while (remain > 0) {
        while(a[i] != b[j]) {
            int top = i>0 ? dp[i-1][j] : 0;
            int left = j>0 ? dp[i][j-1] : 0;
            if (top > left) i--;
            else j--;
        }
        lcs.push_back(a[i]);
        remain--;
        i--;
        j--;
    }
    reverse(lcs.begin(), lcs.end());
    cout << lcs << '\n';

    return 0;
}
