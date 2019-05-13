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
        if (binary_search(arr.begin(), arr.end(), value)) {
            cout << 1 << '\n';
        } else {
            cout << 0 << '\n';
        }
    }
    return 0;
}
