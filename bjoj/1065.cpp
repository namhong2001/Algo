#include <iostream>

using namespace std;

int main() {
    int n;
    int cnt = 0;
    cin >> n;
    for (int i=1; i<=n; ++i) {
        if(i<10) {
            ++cnt;
            continue;
        }

        int c = i;
        int diff = c%10 - c/10%10;

        while(c/10) {
            if (c%10 - c/10%10 != diff) {
                break;
            }
            c /= 10;
        }
        if (c < 10) ++cnt;
    }
    cout << cnt;
    return 0;
}
