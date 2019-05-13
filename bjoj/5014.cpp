#include <iostream>
#include <queue>

using namespace std;

int f, s, g, u, d;

int bfs() {
    vector<int> step(f+1, -1);
    queue<int> q;
    q.push(s);
    step[s] = 0;
    while (!q.empty()) {
        int here = q.front();
        q.pop();
        if (here == g) return step[here];
        if (here+u <= f && step[here+u] == -1) {
            q.push(here+u);
            step[here+u] = step[here]+1;
        }
        if (here-d >= 1 && step[here-d] == -1) {
            q.push(here-d);
            step[here-d] = step[here]+1;
        }
    }
    return -1;
}

int main() {
    cin >> f >> s >> g >> u >> d;
    int ans = bfs();
    if (ans == -1) cout << "use the stairs" << endl;
    else cout << ans << endl;
}
