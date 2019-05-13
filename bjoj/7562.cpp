#include <iostream>
#include <queue>
#include <utility>


using namespace std;
int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

typedef pair<int,int> pii;

int l;

int bfs(pii s, pii e) {
    vector<vector<int>> step(l, vector<int>(l, -1));

    queue<pii> q;
    q.push(s);
    step[s.first][s.second] = 0;
    while (!q.empty()) {
        pii here = q.front();
        q.pop();
        if (here == e) return step[here.first][here.second];

        for (int i=0; i<8; ++i) {
            int x = here.first-dx[i];
            int y = here.second-dy[i];
            if (x<0 || x>=l || y<0 || y>=l) continue;
            if (step[x][y] != -1) continue;
            q.push({x, y});
            step[x][y] = step[here.first][here.second]+1;
        }
    }
    return 0;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> l;
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << bfs({x1, y1}, {x2, y2}) << endl;
    }
    return 0;
}
