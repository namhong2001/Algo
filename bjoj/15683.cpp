#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int N_MAX = 8;
vector<vector<int>> office(N_MAX, vector<int>(N_MAX));
vector<pair<int, int>> cctv_poses;
vector<int> cctv_methods {0, 4, 2, 4, 4, 1};
int ans = 64;
int n, m;

void mark_view(vector<vector<int>> &cur_office, int x, int y, int direction) {
    direction %= 4;
    int directions[4][2] = {
        {1, 0},
        {0, 1},
        {-1, 0},
        {0, -1}
    };
    while (true) {
        x += directions[direction][0];
        y += directions[direction][1];
        if (x<0 || x>=n || y<0 || y>=m || cur_office[x][y] == 6) break;
        else if (cur_office[x][y] == 0) {
            cur_office[x][y] = 9;
        }
    }
}

void cal_blind_spot(const vector<int> &cctv_view) {
    if (cctv_view.size() < cctv_poses.size()) {
        pair<int, int> cur_cctv_pos = cctv_poses[cctv_view.size()];
        int cur_cctv = office[cur_cctv_pos.first][cur_cctv_pos.second];

        for (int i=0; i<cctv_methods[cur_cctv]; ++i) {
            vector<int> new_cctv_view = cctv_view;
            new_cctv_view.push_back(i);
            cal_blind_spot(new_cctv_view);
        }
    } else {
        vector<vector<int>> new_office = office;
        for (int i=0; i<cctv_view.size(); ++i) {
            pair<int, int> cur_cctv_pos = cctv_poses[i];
            int cur_cctv = new_office[cur_cctv_pos.first][cur_cctv_pos.second];
            if (cur_cctv == 1) {
                mark_view(new_office, cur_cctv_pos.first, cur_cctv_pos.second, cctv_view[i]);
            } else if (cur_cctv == 2) {
                mark_view(new_office, cur_cctv_pos.first, cur_cctv_pos.second, cctv_view[i]);
                mark_view(new_office, cur_cctv_pos.first, cur_cctv_pos.second, cctv_view[i]+2);
            } else if (cur_cctv == 3) {
                mark_view(new_office, cur_cctv_pos.first, cur_cctv_pos.second, cctv_view[i]);
                mark_view(new_office, cur_cctv_pos.first, cur_cctv_pos.second, cctv_view[i]+1);
            } else if (cur_cctv == 4) {
                mark_view(new_office, cur_cctv_pos.first, cur_cctv_pos.second, cctv_view[i]);
                mark_view(new_office, cur_cctv_pos.first, cur_cctv_pos.second, cctv_view[i]+1);
                mark_view(new_office, cur_cctv_pos.first, cur_cctv_pos.second, cctv_view[i]+2);
            } else if (cur_cctv == 5) {
                mark_view(new_office, cur_cctv_pos.first, cur_cctv_pos.second, cctv_view[i]);
                mark_view(new_office, cur_cctv_pos.first, cur_cctv_pos.second, cctv_view[i]+1);
                mark_view(new_office, cur_cctv_pos.first, cur_cctv_pos.second, cctv_view[i]+2);
                mark_view(new_office, cur_cctv_pos.first, cur_cctv_pos.second, cctv_view[i]+3);
            }
        }
        int cnt = 0;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                if (new_office[i][j] == 0) cnt++;
            }
        }
        ans = min(ans, cnt);
    }
}

int main() {
    cin >> n >> m;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            cin >> office[i][j];
            if (office[i][j] > 0 && office[i][j] < 6) cctv_poses.push_back({i, j});
        }
    }
    cal_blind_spot({});
    cout << ans;
    return 0;
}
