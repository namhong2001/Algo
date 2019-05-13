#include <iostream>

using namespace std;

int main() {
    int n, mx=0, sum=0, a, cnt;
    cin >> n;
    cnt = n;
    while(n--) {
        cin >> a;
        if (a > mx) {
            mx = a;
        }
        sum += a;
    }
    cout << (double)sum / cnt / mx * 100;
    return 0;
}
