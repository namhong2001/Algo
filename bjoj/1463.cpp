#include <iostream>

using namespace std;
const int N_MAX = 1e6;

int dp[N_MAX+1] = {0};

int get_cnt(int n) {
    if (n == 1) return 0;
    if (dp[n] > 0) return dp[n];
    else {
        int cnt = get_cnt(n-1);
        if (n%3 == 0) cnt = min(cnt, get_cnt(n/3));
        if (n%2 == 0) cnt = min(cnt, get_cnt(n/2));
        ++cnt;
        dp[n] = cnt;
        return cnt;
    }
}

int main() {
    int n;
    cin >> n;
    int cnt = 0;
    cout << get_cnt(n);
    return 0;
}
