#include <iostream>
#include <cstring>

using namespace std;

const int N_MAX = 1000;
int cards[N_MAX];
int cache[N_MAX][N_MAX];
int sum[N_MAX+1];

int solve(int start, int end) {
    if (start > end) return 0;

    int &ret = cache[start][end];
    if (ret != -1) return ret;

    int cand1 = cards[start] + sum[end+1] - sum[start+1] - solve(start+1, end);
    int cand2 = cards[end] + sum[end] - sum[start] - solve(start, end-1);
    ret = max(cand1, cand2);

    return ret;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        sum[0] = 0;
        for (int i=0; i<n; ++i) {
            cin >> cards[i];
            sum[i+1] = sum[i] + cards[i];
        }
        memset(cache, -1, sizeof(cache));
        cout << solve(0, n-1) << endl;
    }

    return 0;
}
