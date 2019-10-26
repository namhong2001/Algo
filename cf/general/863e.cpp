#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Range {
    int s, e, idx;
    bool operator < (Range rhs) {
        return s == rhs.s ? e < rhs.e : s < rhs.s;
    }
};

int main() {
    int N;
    cin >> N;
    vector<Range> arr(N);
    for (int i=0; i<N; ++i) {
        cin >> arr[i].s >> arr[i].e;
        arr[i].idx = i+1;
    }
    sort(arr.begin(), arr.end());
    for (int i=0; i<N-1; ++i) {
        if (arr[i].s == arr[i+1].s) {
            cout << arr[i].idx;
            return 0;
        }
        if (arr[i+1].e <= arr[i].e) {
            cout << arr[i+1].idx;
            return 0;
        }
    }
    for (int i=1; i<N-1; ++i) {
        if (arr[i-1].e+1 >= arr[i+1].s) {
            cout << arr[i].idx;
            return 0;
        }
    }
    cout << -1;
    return 0;
}