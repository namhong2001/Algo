#include <iostream>
#include <cstring>

using namespace std;

const int N_MAX = 101;
const int mod = 1000000007;
int cache[N_MAX];


int solve(int n) {
    if (n == 0 || n == 1) return 1;

    int &ret = cache[n];
    if (ret != -1) return ret;

    ret = solve(n-1) + solve(n-2);
    ret %= mod;
    return ret;
}

int main() {
    int c;
    cin >> c;
    memset(cache, -1, sizeof(cache));
    while (c--) {
        int n;
        cin >> n;
        cout << solve(n) << endl;
    }

    return 0;
}
