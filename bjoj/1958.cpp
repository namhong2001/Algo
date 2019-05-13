#include <iostream>
#include <algorithm>

using namespace std;

const int L_MAX = 100;

string str1, str2, str3;
int cache[L_MAX+1][L_MAX+1][L_MAX+1];

int main() {
    cin >> str1 >> str2 >> str3;

    int ans = 0;
    for (int i=1; i<=str1.size(); ++i) {
        for (int j=1; j<=str2.size(); ++j) {
            for (int k=1; k<=str3.size(); ++k) {
                if (str1[i-1] == str2[j-1] && str2[j-1] == str3[k-1]) {
                    cache[i][j][k] = cache[i-1][j-1][k-1] + 1;
                    ans = max(ans, cache[i][j][k]);
                } else {
                    cache[i][j][k] = cache[i-1][j][k];
                    cache[i][j][k] = max(cache[i][j][k], cache[i][j-1][k]);
                    cache[i][j][k] = max(cache[i][j][k], cache[i][j][k-1]);
                }
            }
        }
    }
    cout << ans;
    return 0;
}
