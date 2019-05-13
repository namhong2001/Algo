#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstdlib>

using namespace std;

const int N_MAX = 50;
int map[N_MAX][N_MAX];
vector<pair<int, int>> houses;
vector<pair<int, int>> chickens;


int main() {
    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            int a;
            cin >> a;
            if (a == 1) {
                houses.push_back({i, j});
            } else if (a == 2) {
                chickens.push_back({i, j});
            }
        }
    }
    vector<int> choose(chickens.size());
    for (int i=0; i<chickens.size()-m; ++i) {
        choose[i] = 0;
    }
    for (int i=chickens.size()-m; i<chickens.size(); ++i) {
        choose[i] = 1;
    }
    int min_dist_sum = 987654321;
    do {
        int dist_sum = 0;
        for (pair<int, int> house : houses) {
            int min_dist = 987654321;
            for (int i=0; i<chickens.size(); ++i) {
                if (choose[i] == 1) {
                    int dist = abs(chickens[i].first - house.first) + abs(chickens[i].second - house.second);
                    min_dist = min(min_dist, dist);
                }
            }
            dist_sum += min_dist;
        }
        min_dist_sum = min(min_dist_sum, dist_sum);
    } while (next_permutation(choose.begin(), choose.end()));

    cout << min_dist_sum;
    return 0;
}
