#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

typedef pair<int,char> pic;

const int LIMIT = 1e4;

stack<char> bfs(int s, int e) {
    bool visited[LIMIT];
    memset(visited, false, sizeof(visited));
    pic p[LIMIT];
    queue<int> q;
    q.push(s);
    visited[s] = true;
    p[s] = {s, 0};
    while (!q.empty()) {
        int here = q.front();
        q.pop();
        if (here == e) {
            int t = here;
            stack<char> ret;
            while (t != s) {
                ret.push(p[t].second);
                t = p[t].first;
            }
            return ret;
        }
        int next = here*2 % LIMIT;
        if (!visited[next]) {
            visited[next] = true;
            q.push(next);
            p[next] = {here, 'D'};
        }
        next = here-1;
        if (next < 0) next += LIMIT;
        if (!visited[next]) {
            visited[next] = true;
            q.push(next);
            p[next] = {here, 'S'};
        }
        next = here*10;
        next += next/LIMIT;
        next %= LIMIT;
        if (!visited[next]) {
            visited[next] = true;
            q.push(next);
            p[next] = {here, 'L'};
        }
        int t = here % 10;
        next = here/10;
        next += t*1e3;
        if (!visited[next]) {
            visited[next] = true;
            q.push(next);
            p[next] = {here, 'R'};
        }
    }

    return stack<char>();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        stack<char> ans = bfs(a, b);
        while (!ans.empty()) {
            cout << ans.top();
            ans.pop();
        }
        cout << '\n';
    }
    return 0;
}
