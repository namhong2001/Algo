#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (a%b == 0) return b;
    else return gcd(b, a%b);
}

long long int lcm(long long int a, long long int b) {
    int g = a>b ? gcd(a,b) : gcd(b,a);
    return a / g * b;
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << lcm(a, b);

    return 0;
}

