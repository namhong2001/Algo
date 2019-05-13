#include <iostream>
#include <cstdlib>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    if (b>a) swap(a,b);
    return a%b ? gcd(b, a%b) : b;
}

int main() {
    int n;
    cin >> n;
    vector<int> gap;
    int prev;
    cin >> prev;
    while (--n) {
        int now;
        cin >> now;
        gap.push_back(abs(now-prev));
        prev = now;
    }
    int g = gap[0];
    for (auto i : gap) {
        g = gcd(g, i);
    }
    vector<int> divisors;
    for (int i=2; i*i<=g; ++i) {
        if (g % i == 0) {
            divisors.push_back(i);
            if (i != g/i) {
                divisors.push_back(g/i);
            }
        }
    }
    divisors.push_back(g);
    sort(divisors.begin(), divisors.end());
    for (auto divisor : divisors) {
        cout << divisor << ' ';
    }

    return 0;
}
