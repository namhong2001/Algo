#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int sum = 0;
    int ans = 0;
    for (int i=0; i<4; ++i) {
        int in;
        int out;
        cin >> out >> in;
        sum -= out;
        sum += in;
        ans = max(ans, sum);
    }
    cout << ans;

    return 0;
}
