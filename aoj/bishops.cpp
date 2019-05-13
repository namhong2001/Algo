#include <iostream>
#include <cstring>
#include <vector>


using namespace std;

const int dx[2] = {1, -1};
const int dy[2] = {1, 1};

vector<string> board;

int id[2][8][8];
int n, m;
int adj[64][64];

vector<int> amatch, bmatch;
vector<bool> visited;

bool dfs(int a) {
    if (visited[a]) return false;
    visited[a] = true;
    for (int b=0; b<m; ++b) {
        if (adj[a][b]) {
            if (bmatch[b] == -1 || dfs(bmatch[b])) {
                amatch[a] = b;
                bmatch[b] = a;
                return true;
            }
        }
    }
    return false;
}

int bipartite_match() {
    amatch = vector<int>(n, -1);
    bmatch = vector<int>(m, -1);
    int sz = 0;
    for (int i=0; i<n; ++i) {
        visited = vector<bool>(n, false);
        if (dfs(i)) ++sz;
    }
    return sz;
}

int place_bishops() {
    memset(id, -1, sizeof(id));
    int cnt[2] = {0, 0};
    for (int dir=0; dir<2; ++dir) {
        for (int x=0; x<board.size(); ++x) {
            for (int y=0; y<board.size(); ++y) {
                if (board[x][y] == '.' && id[dir][x][y] == -1) {
                    int cy = y, cx = x;
                    while (0 <= cx && cx < board.size() &&
                           0 <= cy && cy < board.size() &&
                           board[cx][cy] == '.') {
                        id[dir][cx][cy] = cnt[dir];
                        cx += dx[dir];
                        cy += dy[dir];
                    }
                    cnt[dir]++;
                }
            }
        }
    }
    n = cnt[0];
    m = cnt[1];
    memset(adj, 0, sizeof(adj));
    for (int x=0; x<board.size(); ++x) {
        for (int y=0; y<board.size(); ++y) {
            if (board[x][y] == '.') {
                adj[id[0][x][y]][id[1][x][y]] = 1;
            }
        }
    }
    return bipartite_match();
}



int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        board.resize(N);
        for (int i=0; i<N; ++i) {
            cin >> board[i];
        }
        cout << place_bishops() << '\n';
    }

    return 0;
}
