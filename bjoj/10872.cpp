#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    long long int ret = 1;
    for (int i=1; i<=n; ++i) {
        ret *= i;
    }
    cout << ret;



    return 0;
}
