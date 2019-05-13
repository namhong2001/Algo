#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t=1; t<=T; ++t) {
        int P, Q;
        cin >> P >> Q;
        vector<int> to_w, to_s, to_e, to_n;
        for (int i=0; i<P; ++i)  {
            int x, y;
            string dir;
            cin >> x >> y >> dir;
            if (dir == "W") {
                to_w.push_back(x);
            } else if (dir == "E") {
                to_e.push_back(x);
            } else if (dir == "N") {
                to_n.push_back(y);
            } else if (dir == "S") {
                to_s.push_back(y);
            }
        }
        sort(to_w.begin(), to_w.end());
        sort(to_e.begin(), to_e.end());
        sort(to_n.begin(), to_n.end());
        sort(to_s.begin(), to_s.end());
        int w_cnt=0, e_cnt=0, s_cnt=0, n_cnt=0;
        int x_max = 0, x_pos = 0;
        int y_max = 0, y_pos = 0;
        for (int x=0; x<=Q; ++x) {
            while(w_cnt < to_w.size() && to_w[w_cnt] <= x) w_cnt++;
            while(e_cnt < to_e.size() && to_e[e_cnt] < x) e_cnt++;
            int candi = to_w.size() - w_cnt + e_cnt;
            if (candi > x_max) {
                x_max = candi;
                x_pos = x;
            }
        }
        for (int y=0; y<=Q; ++y) {
            while(n_cnt < to_n.size() && to_n[n_cnt] < y) n_cnt++;
            while(s_cnt < to_s.size() && to_s[s_cnt] <= y) s_cnt++;
            int candi = to_s.size() - s_cnt + n_cnt;
            if (candi > y_max) {
                y_max = candi;
                y_pos = y;
            }
        }
        cout << "Case #" << t << ": " << x_pos << ' ' << y_pos << '\n';
    }
    return 0;
}
