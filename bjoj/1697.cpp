#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int ans[100000];

int solve(int x, int y) {
    if (x == y) return 0;
    memset(ans, -1, sizeof(ans));
    ans[x] = 0;
    queue<int> q;
    q.push(x);
    while (!q.empty()) {
        int here = q.front();
        q.pop();
        int theres[3] = {here-1, here+1, here*2};
        for (int i=0; i<3; ++i) {
            int there = theres[i];
            if (there < 0 || there > 100000) continue;

            if (there == y) return ans[here]+1;

            if (ans[there] == -1) {
                ans[there] = ans[here]+1;
                q.push(there);
            }
        }
    }
    return -1;
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << solve(n, k) << endl;
    return 0;
}
