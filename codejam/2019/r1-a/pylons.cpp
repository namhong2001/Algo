#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

vector<vector<int>> discovered;


int R, C;

bool can_move(const pair<int,int> &a, const pair<int,int> &b) {
    if (a.first == b.first) return false;
    if (a.second == b.second) return false;
    if (a.first - a.second == b.first - b.second) return false;
    if (a.first + a.second == b.first + b.second) return false;
    return true;
}


vector<pair<int,int>> solve(int r, int c) {
    for (int iter=0; iter<1000; ++iter) {
        vector<vector<bool>> visited(r, vector<bool>(c, false));
        vector<pair<int,int>> path;
        vector<pair<int,int>> moves;
        for (int i=0; i<r; ++i) {
            for (int j=0; j<c; ++j) {
                moves.push_back({i, j});
            }
        }

        while (!moves.empty()) {
            int idx = rand() % moves.size();
            pair<int,int> here = moves[idx];
            visited[here.first][here.second] = true;
            path.push_back(here);
            moves.clear();
            for (int i=0; i<r; ++i) {
                for (int j=0; j<c; ++j) {
                    if (!visited[i][j] && can_move(here, {i, j})) {
                        moves.push_back({i, j});
                    }
                }
            }
        }
        if (path.size() == r*c) return path;
    }
    return vector<pair<int,int>>();
}


int main() {
    srand(time(nullptr));
    int T;
    cin >> T;
    for (int t=1; t<=T; ++t) {
        cin >> R >> C;
        vector<pair<int,int>> ans = solve(R, C);
        if (ans.empty()) {
            cout << "Case #" << t << ": " << "IMPOSSIBLE" << endl;
        } else {
            cout << "Case #" << t << ": " << "POSSIBLE" << endl;
            for (pair<int,int> &a : ans) {
                cout << a.first+1 << ' ' << a.second+1 << endl;
            }
        }
    }
    return 0;
}

