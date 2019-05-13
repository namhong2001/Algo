#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int times[501];
vector<int> children[501];
int dp[501];

int total(int me) {
    int &ret = dp[me];
    if (ret > 0) return ret;

    ret = times[me];

    int child_max = 0;

    for (int child : children[me]) {
        child_max = max(child_max, total(child));
    }
    ret += child_max;

    return ret;
}

int main() {
    int n;
    cin >> n;
    for (int i=1; i<=n; ++i) {
        cin >> times[i];
        while (true) {
            int child;
            cin >> child;
            if (child == -1) break;
            children[i].push_back(child);
        }
    }
    for (int i=1; i<=n; ++i) {
        cout << total(i) << endl;
    }

    return 0;
}
