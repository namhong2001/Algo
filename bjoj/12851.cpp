#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int ans[100000];
int cnt[100000];

void solve(int x, int y) {
    memset(ans, -1, sizeof(ans));
    ans[x] = 0;
    cnt[x] = 1;
    int finish_level = 100000;


    queue<int> q;
    q.push(x);
    while (!q.empty()) {
        int here = q.front();

        if (ans[here] >= finish_level) return;

        q.pop();
        int theres[3] = {here-1, here+1, here*2};
        for (int i=0; i<3; ++i) {
            int there = theres[i];
            if (there < 0 || there > 100000) continue;

            if (ans[there] == -1) {
                ans[there] = ans[here]+1;
                cnt[there] = cnt[here];
                if (there == y) {
                    finish_level = ans[there];
                }
                q.push(there);
            } else if (ans[there] == ans[here] + 1) {
                cnt[there] += cnt[here];
            }
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    if (n == k) {
        ans[n] = 0;
        cnt[n] = 1;
    } else {
        solve(n, k);
    }

    cout << ans[k] << '\n' << cnt[k];
    return 0;
}

