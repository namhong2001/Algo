#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    int round = 1;

    while (true) {
        if (abs(a-b) == 1 && min(a,b)%2 == 1) break;
        a = (a+1)/2;
        b = (b+1)/2;
        ++round;
    }
    cout << round;
    return 0;
}
