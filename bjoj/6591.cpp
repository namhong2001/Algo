#include <iostream>
#include <vector>


using namespace std;

int gcd(int a, int b) {
    if (b > a) {
        int temp = a;
        a = b;
        b = temp;
    }
    return a%b == 0 ? b : gcd(b, a%b);
}

int comb(int n, int k) {
    int div_max = n-k > k ? n-k : k;
    vector<int> upper;
    vector<int> factor;
    for (int i=div_max+1; i<=n; ++i) {
        upper.push_back(i);
    }
    for (int i=1; i<=n-div_max; ++i) {
        factor.push_back(i);
    }
    for (auto div : factor) {
        for (int j=0; j < upper.size(); ++j) {
            int my_gcd = gcd(upper[j], div);
            div /=  my_gcd;
            upper[j] /= my_gcd;
            if (div == 1) break;
        }
    }
    int ret = 1;
    for (auto num : upper) {
        ret *= num;
    }
    return ret;
}

int main() {
    while (true) {
        int n, k;
        cin >> n >> k;
        if (n == 0 && k == 0) break;
        cout << comb(n, k) << '\n';
    }
    return 0;
}
