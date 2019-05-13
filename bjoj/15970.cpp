#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int N_MAX = 5001;

vector<int> colors[N_MAX];

int main() {
    int n;
    int x, y;
    cin >> n;
    int ans = 0;
    for (int i=0; i<n; ++i) {
        cin >> x >> y;
        colors[y].push_back(x);
    }
    for (int i=1; i<=n; ++i) {
        vector<int>& target = colors[i];
        if (target.empty()) continue;
        sort(target.begin(), target.end());
        for (int j=0; j<target.size(); ++j) {
            if (j == 0) {
                ans += abs(target[j] - target[j+1]);
            } else if (j == target.size()-1) {
                ans += abs(target[j] - target[j-1]);
            } else {
                ans += min(abs(target[j] - target[j+1]), abs(target[j] - target[j-1]));
            }

        }
    }
    cout << ans;

    return 0;
}
