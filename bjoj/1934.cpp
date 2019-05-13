#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (a%b == 0) return b;
    else return gcd(b, a%b);
}

int lcm(int a, int b) {
    int g = a>b ? gcd(a,b) : gcd(b,a);
    return a / g * b;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        cout << lcm(a, b) << '\n';
    }

    return 0;
}
