#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N_MAX = 100;
const long long INF = 987654321987654321;

long long cost[N_MAX];
long long cache[N_MAX][N_MAX][2];
long long sum[N_MAX+1];
int n, s_pos;

long long dist(int a, int b) {
    return sum[max(a, b)] - sum[min(a, b)];
}

long long solve(int left, int right, int last_pos) {
    if (left == 0 && right == n-1) return 0;

    long long &ret = cache[left][right][last_pos];
    if (ret != -1) return ret;

    ret = INF;
    int remain_nodes = n - right + left - 1;
    if (last_pos == 0) {
        if (left > 0)
            ret = min(ret, solve(left-1, right, 0) + remain_nodes*dist(left-1, left));
        if (right < n-1)
            ret = min(ret, solve(left, right+1, 1) + remain_nodes*dist(left, right+1));
    } else {
        if (left > 0)
            ret = min(ret, solve(left-1, right, 0) + remain_nodes*dist(left-1, right));
        if (right < n-1)
            ret = min(ret, solve(left, right+1, 1) + remain_nodes*dist(right, right+1));
    }
    return ret;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> s_pos;
        s_pos--;
        memset(cache, -1, sizeof(cache));
        sum[0] = 0;
        for (int i=0; i<n-1; ++i) {
            cin >> cost[i];
            sum[i+1] = sum[i] + cost[i];
        }
        cout << solve(s_pos, s_pos, 0) << endl;
    }

    return 0;
}
