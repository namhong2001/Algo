#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

set<pair<int,int>> plates;
int dp[601][601];

int solve(int w, int h) {
    int &ret = dp[w][h];
    if (ret != -1) return ret;

    if (plates.find({w, h}) != plates.end()) {
        ret = 0;
        return ret;
    }

    ret = w*h;
    for (int wi=1; wi<=w/2; ++wi) {
        ret = min(ret, solve(wi, h)+solve(w-wi, h));
    }
    for (int hi=1; hi<=h/2; ++hi) {
        ret = min(ret, solve(w, hi)+solve(w, h-hi));
    }
    return ret;
}


int main() {
    int w, h, n;
    cin >> w >> h;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    for (int i=0; i<n; ++i) {
        int a, b;
        cin >> a >> b;
        plates.insert({a, b});
    }
    cout << solve(w, h) << endl;
    return 0;
}
