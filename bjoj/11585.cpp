#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector<int> getPartialMatch(const string& N) {
    int m = N.size();
    vector<int> pi(m, 0);
    int matched = 0;
    for (int i=1; i<m; ++i) {
        while(matched > 0 && N[i] != N[matched]) {
            matched = pi[matched-1];
        }
        if(N[i] == N[matched]) {
            ++matched;
            pi[i] = matched;
        }
    }
    return pi;
}

vector<int> kmpSearch(const string& H, const string& N) {
    int h = H.size();
    int n = N.size();
    vector<int> pi = getPartialMatch(N);
    vector<int> ret;
    int matched = 0;
    for (int i=0; i<h; ++i) {
        while(matched > 0 && H[i] != N[matched]) {
            matched = pi[matched-1];
        }
        if(H[i] == N[matched]) {
            ++matched;
            if (matched == n) {
                ret.push_back(i - matched + 1);
                matched = pi[matched-1];
            }
        }
    }
    return ret;
}

int getGcd(int a, int b) {
    return a % b ? getGcd(b, a%b) : b;
}

int main() {
    int n;
    cin >> n;
    char c_str[n+1];
    c_str[n] = '\0';
    for (int i=0; i<n; ++i) {
        scanf(" %c", &c_str[i]);
    }
    for (int i=0; i<n; ++i) {
        scanf(" %*c");
    }
    string s(c_str);
    vector<int> kmp = kmpSearch(s+s, s);
    int meat = kmp.size()-1;

    int gcd = getGcd(n, meat);
    cout << meat/gcd << '/' << n/gcd;

    return 0;
}
