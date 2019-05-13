#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    map<int, int> nodes;
    int n;
    cin >> n;
    long long int cnt=0;

    while(n--) {
        int num, level;
        cin >> num;
        auto upper = nodes.lower_bound(num);
        auto lower = upper;
        if (lower != nodes.begin()) --lower;
        if (nodes.size() == 0) {
            level = 0;
        } else {
            level = max(upper->second, lower->second) + 1;
        }
        nodes.insert({num, level});
        cnt += level;
        cout << cnt << '\n';
    }
    return 0;
}
