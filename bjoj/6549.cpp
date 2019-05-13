#include <iostream>
#include <algorithm>


using namespace std;

const int N_MAX = 100000;
int height[N_MAX];

long long int solve(int left, int right) {
    if (left == right) return height[left];

    int half = (left+right)/2;
    long long int ret = max(solve(left, half), solve(half+1, right));
    int lo = half;
    int hi = half+1;
    int cur_height = min(height[lo], height[hi]);
    ret = max(ret, cur_height*2ll);
    while (left < lo || hi < right) {
        if (left < lo && (hi == right || height[lo-1] > height[hi+1])) {
            lo--;
            cur_height = min(cur_height, height[lo]);
        } else {
            hi++;
            cur_height = min(cur_height, height[hi]);
        }

        ret = max(ret, (hi-lo+1)*(long long int)cur_height);
    }
    return ret;

}

int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) return 0;

        for (int i=0; i<n; ++i) {
            cin >> height[i];
        }
        cout << solve(0, n-1) << endl;
    }
}
