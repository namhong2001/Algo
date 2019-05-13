#include <iostream>

using namespace std;


long long int gcd(long long int a, long long int b) {
    if (a%b == 0) return b;
    else return gcd(b, a%b);
}


int main() {
    long long int a, b;
    cin >> a >> b;
    long long int g = gcd(a,b);
    for (int i=0; i<g; ++i) {
        cout << 1;
    }
    return 0;
}
