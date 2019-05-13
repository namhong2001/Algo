#include <iostream>

using namespace std;

int gcd(int a, int b) {
    return a%b ? gcd(b, a%b) : b;
}
int lcm(int a, int b) {
    int g = gcd(a, b);
    return a / g * b;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        int g = gcd(b, a);
        a /= g;
        b /= g;
        while (a != 1) {
            int x = (b/a) + 1;
            int c_div = lcm(b, x);
            a *= c_div/b;
            a -= c_div/x;
            b = c_div;
            g = gcd(b, a);
            a /= g;
            b /= g;
        }
        cout << b << '\n';
    }

    return 0;
}
