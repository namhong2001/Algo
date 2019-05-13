#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>

using namespace std;

vector<string> board;
unordered_set<int> radio_v;
unordered_set<int> radio_h;
set<pair<int,int>> possible_coord_h;
set<pair<int,int>> possible_coord_v;


const int HDIR = 0;
const int VDIR = 1;


int R, C;


bool can_win(int sx, int sy, int dir, int cnt) {
    cout << sx << ' ' << sy << ' ' << dir << ' ' << cnt << endl;
    vector<pair<int,int>> restore_h;
    vector<pair<int,int>> restore_v;
    vector<pair<int,int>> restore_b;

    if (dir == HDIR) {
        int i=sx;
        for (int j=sy; j>=0; --j) { // to west
            if (board[i][j] == '.') {
                board[i][j] = 'A';
                restore_b.push_back({i, j});
                if (possible_coord_h.find({i, j}) != possible_coord_h.end()) {
                    possible_coord_h.erase({i, j});
                    restore_h.push_back({i, j});
                }
                if (possible_coord_v.find({i, j}) != possible_coord_v.end()) {
                    possible_coord_v.erase({i, j});
                    restore_v.push_back({i, j});
                }
            } else break;

        }
        for (int j=sy+1; j<C; ++j) { // to east
            if (board[i][j] == '.') {
                board[i][j] = 'A';
                restore_b.push_back({i, j});
                if (possible_coord_h.find({i, j}) != possible_coord_h.end()) {
                    possible_coord_h.erase({i, j});
                    restore_h.push_back({i, j});
                }
                if (possible_coord_v.find({i, j}) != possible_coord_v.end()) {
                    possible_coord_v.erase({i, j});
                    restore_v.push_back({i, j});
                }
            } else break;
        }
    } else {
        int j=sy;
        for (int i=sx; i>=0; --i) { // to n
            if (board[i][j] == '.') {
                board[i][j] = 'A';
                restore_b.push_back({i, j});
                if (possible_coord_h.find({i, j}) != possible_coord_h.end()) {
                    possible_coord_h.erase({i, j});
                    restore_h.push_back({i, j});
                }
                if (possible_coord_v.find({i, j}) != possible_coord_v.end()) {
                    possible_coord_v.erase({i, j});
                    restore_v.push_back({i, j});
                }
            } else break;
        }
        for (int i=sx+1; i<R; ++i) { // to s
            if (board[i][j] == '.') {
                board[i][j] = 'A';
                restore_b.push_back({i, j});
                if (possible_coord_h.find({i, j}) != possible_coord_h.end()) {
                    possible_coord_h.erase({i, j});
                    restore_h.push_back({i, j});
                }
                if (possible_coord_v.find({i, j}) != possible_coord_v.end()) {
                    possible_coord_v.erase({i, j});
                    restore_v.push_back({i, j});
                }
            } else break;
        }
    }
//    cout << possible_coord_h.size() << ' ' << possible_coord_v.size() << endl;


    bool ret = false;
    if (possible_coord_h.empty() && possible_coord_v.empty()) {
        if (cnt%2) ret = false;
        else ret = true;
    }
    for (pair<int,int> p : possible_coord_h) {
        bool result = can_win(p.first, p.second, HDIR, cnt+1);
        ret = ret || result;
    }
    for (pair<int,int> p : possible_coord_v) {
        bool result = can_win(p.first, p.second, VDIR, cnt+1);
        ret = ret || result;
    }
    //restore
    for (pair<int,int> &p : restore_b) {
        board[p.first][p.second] = '.';
    }
    for (pair<int,int> &p : restore_v) {
        possible_coord_v.insert(p);
    }
    for (pair<int,int> &p : restore_h) {
        possible_coord_h.insert(p);
    }
    return ret;
}

int main() {
    int T;
    cin >> T;
    for (int t=1; t<=T; ++t) {

        cin >> R >> C;
        board.clear();
        radio_v.clear();
        radio_h.clear();
        possible_coord_h.clear();
        possible_coord_v.clear();
        for (int i=0; i<R; ++i) {
            string s;
            cin >> s;
            board.push_back(s);
            for (int j=0; j<C; ++j) {
                if (board[i][j] == '#') {
                    radio_v.insert(j);
                    radio_h.insert(i);
                }
            }
        }
        for (int i=0; i<R; ++i) {
            for (int j=0; j<C; ++j) {
                if (board[i][j] == '.') {
                    if (radio_v.find(j) == radio_v.end()) {
                        possible_coord_v.insert({i, j});
                    }
                    if (radio_h.find(i) == radio_h.end()) {
                        possible_coord_h.insert({i, j});
                    }
                }
            }
        }
        int ans = 0;
        for (pair<int,int> p : possible_coord_h) {
            if (can_win(p.first, p.second, HDIR, 0)) ans++;
        }
        for (pair<int,int> p : possible_coord_v) {
            if (can_win(p.first, p.second, VDIR, 0)) ans++;
        }
        cout << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}
