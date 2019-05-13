#include <cstdio>
#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

using BigInt = deque<int>;

BigInt operator * (const BigInt &a, const BigInt &b);

void normalize(BigInt &a) {
    int a_size = a.size();
    for (int i=0; i<a_size; ++i) {
        a.push_back(0);
    }
    for (int i=0; i<a.size()-1; ++i) {
        a[i+1] += a[i] / 10;
        a[i] %= 10;
        if (a[i] < 0) {
            a[i] += 10;
            a[i+1]--;
        }
    }
    for (int i=a.size()-1; i>0; --i) {
        if (a[i] == 0) a.pop_back();
        else break;
    }
}

BigInt operator + (const BigInt &a, const BigInt &b) {
    if (a.size() < b.size()) return b+a;

    BigInt ret = a;
    for (int i=0; i<b.size(); ++i) {
        ret[i] += b[i];
    }
    normalize(ret);
    return ret;
}

BigInt operator - (const BigInt &a, const BigInt &b) {
    BigInt ret = a;
    for (int i=0; i<b.size(); ++i) {
        ret[i] -= b[i];
    }
    normalize(ret);
    return ret;
}

BigInt On2_multiple(const BigInt &a, const BigInt &b) {
    BigInt ret(a.size() + b.size());
    for (int i=0; i<a.size(); ++i){
        for (int j=0; j<b.size(); ++j) {
            ret[i+j] += a[i] * b[j];
        }
    }
    normalize(ret);
    return ret;
}

BigInt& pow_10(BigInt &a, int k) {
    while (k--) a.push_front(0);
    return a;
}

BigInt karatsuba_multiple(const BigInt &a, const BigInt &b) {
    int a_size = a.size();
    int b_size = b.size();

    int half = a_size/2;
    BigInt A0(a.begin(), a.begin()+half);
    BigInt A1(a.begin()+half, a.end());

    BigInt B0(b.begin(), b.begin() + min(b_size, half));
    BigInt B1(b.begin() + min(b_size, half), b.end());

    BigInt X2 = A1 * B1;
    BigInt X0 = A0 * B0;
    BigInt X1 = (A1 + A0) * (B1 + B0) - X2 - X0;
    return pow_10(X2, half*2) + pow_10(X1, half) + X0;
}

BigInt operator * (const BigInt &a, const BigInt &b) {
    int a_size = a.size();
    int b_size = b.size();
    if (a_size < b_size) return b*a;

    if (a_size < 50) {
        return On2_multiple(a, b);
    } else {
        return karatsuba_multiple(a, b);
    }
}

ostream& operator << (ostream& os ,const BigInt &a) {
    for (int i=a.size()-1; i>=0; --i) {
        os << a[i];
    }
    return os;
}


int main() {
    ios::sync_with_stdio(false);

    BigInt A;
    BigInt B;
    int c;
    while (true) {
        int c = getchar();
        if (c == ' ') break;
        A.push_back(c - '0');
    }
    while (true) {
        int c = getchar();
        if (c == -1 || c == '\n') break;
        B.push_back(c - '0');
    }

    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());

    cout << A * B;
    return 0;
}
