#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
    bool operator < (const Point &rhs) const {
        return y == rhs.y ? x < rhs.x : y < rhs.y;
    }
}; 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N;
    cin >> N;
    vector<Point> arr(N);
    for (int i=0; i<N; ++i) {
        cin >> arr[i].x >> arr[i].y;
    }
    sort(arr.begin(), arr.end()); 
    for (int i=0; i<N; ++i) {
        cout << arr[i].x << ' ' << arr[i].y << '\n';
    } 
    return 0;
}

