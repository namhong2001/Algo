#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i=0; i<n; ++i) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    int m;
    cin >> m;
    for (int i=0; i<m; ++i) {
        int value;
        cin >> value;
        auto lower = lower_bound(arr.begin(), arr.end(), value);
        if (lower == arr.end() || *lower != value) {
            cout << 0 << '\n';
        } else {
            cout << 1 << '\n';
        }
    }
    return 0;
}
