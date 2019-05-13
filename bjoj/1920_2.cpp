#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


bool bs(int first, int last, int val, vector<int> &arr) {
    int cnt = last - first;
    while (cnt>0) {
        int step = cnt/2;
        int mid = first+step;
        if (arr[mid] < val) {
            first = mid+1;
            cnt -= step+1;
        } else {
            cnt = step;
        }
    }
    if (first == last || arr[first] != val) return false;
    return true;
}

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
        if (bs(0, arr.size(), value, arr)) {
            cout << 1 << '\n';
        } else {
            cout << 0 << '\n';
        }
    }
    return 0;
}
