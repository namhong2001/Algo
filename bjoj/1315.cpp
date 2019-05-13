#include <iostream>
#include <vector>
#include <utility>
#include <unordered_set>
#include <algorithm>

using namespace std;

const int N_MAX = 100;

vector<pair<int, int>> strong;
vector<pair<int, int>> intelli;
int plus_points[N_MAX+1];

int gained_points[N_MAX+1][N_MAX+1];
unordered_set<int> picked_quests[N_MAX+1][N_MAX+1];


int required_points(int str_idx, int int_idx) {
    int str_point = strong[str_idx].first;
    int int_point = intelli[int_idx].first;
    return str_point - strong[0].first + int_point - intelli[0].first;
}

int main() {
    int n;
    cin >> n;
    strong.push_back({1, 0});
    intelli.push_back({1, 0});
    plus_points[0] = 0;
    gained_points[0][0] = 0;

    for (int i=1; i<=n; ++i) {
        int str, intel;
        cin >> str >> intel >> plus_points[i];
        strong.push_back({str, i});
        intelli.push_back({intel, i});
    }
    sort(strong.begin(), strong.end());
    sort(intelli.begin(), intelli.end());

    int ans = 0;

    for (int i=0; i<=n; ++i) {
        for (int j=0; j<=n; ++j) {
            if (i>0 && gained_points[i-1][j] >= required_points(i, j)) {
                int index = strong[i].second;
                picked_quests[i][j] = picked_quests[i-1][j];
                gained_points[i][j] = gained_points[i-1][j];
                if (picked_quests[i][j].find(index) == picked_quests[i][j].end()) {
                    picked_quests[i][j].insert(index);
                    gained_points[i][j] += plus_points[index];
                }
                ans = max(ans, (int)picked_quests[i][j].size());
            } else if (j>0 && gained_points[i][j-1] >= required_points(i, j)) {
                int index = intelli[j].second;
                picked_quests[i][j] = picked_quests[i][j-1];
                gained_points[i][j] = gained_points[i][j-1];
                if (picked_quests[i][j].find(index) == picked_quests[i][j].end()) {
                    picked_quests[i][j].insert(index);
                    gained_points[i][j] += plus_points[index];
                }
                ans = max(ans, (int)picked_quests[i][j].size());
            }
        }
    }
    cout << ans;

    return 0;
}


