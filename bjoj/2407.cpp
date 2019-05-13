#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

typedef vector<int> big_int;
const int cell_limit = 1e9;
const int max_decimal = 9;

big_int operator + (const big_int &a, const big_int &b) {
    int a_size = a.size();
    int b_size = b.size();
    bool big_left = a_size > b_size;
    int max_size;
    int min_size;
    if (big_left) {
        max_size = a_size;
        min_size = b_size;
    } else {
        max_size = b_size;
        min_size = a_size;
    }
    big_int ret(max_size);
    int carry = 0;
    for (int i=0; i<min_size; ++i) {
        int num = a[i] + b[i] + carry;
        carry = 0;
        if (num >= cell_limit) {
            carry = 1;
            num -= cell_limit;
        }
        ret[i] = num;
    }

    if (max_size > min_size) {
        for (int i=min_size; i<max_size; ++i) {
            const big_int &max_num = big_left ? a : b;
            int num = max_num[i] + carry;
            carry = 0;
            if (num >= cell_limit) {
                carry = 1;
                num -= cell_limit;
            }
            ret[i] = num;
        }
    }
    if (carry == 1) {
        ret.push_back(carry);
    }
    return ret;
}

ostream& operator << (ostream& os, const big_int &a) {
    os << a[a.size()-1];
    os << setfill('0');
    for (int i=a.size()-2; i>=0; --i) {
        os << setw(max_decimal) << a[i];
    }
    return os;
}

const int N_MAX = 100;

int main() {
    int n, m;
    cin >> n >> m;

    big_int dp[N_MAX+1];
    dp[0] = big_int(1,1);
    for (int i=0; i<n; ++i) {
        dp[i+1] = big_int(1,1);
        for (int j=i; j>0; --j) {
            dp[j] = dp[j] + dp[j-1];
        }
    }
    cout << dp[m];
    return 0;
}
