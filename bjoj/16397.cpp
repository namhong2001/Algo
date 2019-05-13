#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int LIMIT = 1e5;

int n, t, g;
int step[LIMIT];

int bfs() {
    memset(step, -1, sizeof(step));
    queue<int> q;
    q.push(n);
    step[n] = 0;
    while (!q.empty()) {
        int here = q.front();
        q.pop();
        if (step[here] > t) break;
        if (here == g) return step[here];
        int next = here+1;

        if (next < LIMIT && step[next] == -1) {
            q.push(next);
            step[next] = step[here]+1;
        }
        next = here*2;
        if (next < LIMIT) {
            if (next != 0) {
                int m = 1;
                while (next / m) {
                    m*=10;
                }
                m/=10;
                next -= m;
            }
            if (step[next] == -1) {
                q.push(next);
                step[next] = step[here]+1;
            }
        }
    }
    return -1;
}

int main() {
    cin >> n >> t >> g;
    int ans = bfs();
    if (ans == -1) cout << "ANG" << endl;
    else cout << ans << endl;

    return 0;
}
