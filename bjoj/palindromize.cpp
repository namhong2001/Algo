#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> getPartialMatch(const string& N) {
    int m = N.size();
    vector<int> pi(m, 0);
    int begin = 1, matched = 0;
    while(begin + matched < m) {
        if(N[begin + matched] == N[matched]) {
            ++matched;
            pi[begin + matched - 1] = matched;
        } else {
            if (matched == 0) {
                ++begin;
            } else {
                begin += matched - pi[matched-1];
                matched = pi[matched-1];
            }
        }
    }
    return pi;
}


int main() {

    int c;
    cin >> c;
    while (c--) {
        string s, r;
        cin >> s;
        r = s;
        reverse(r.begin(), r.end());

        vector<int> pi = getPartialMatch(r);

        int m = s.size();
        int begin = 0, matched = 0;
        while(begin + matched < m) {
            if(s[begin + matched] == r[matched]) {
                ++matched;
            } else {
                if (matched == 0) {
                    ++begin;
                } else {
                    begin += matched - pi[matched-1];
                    matched = pi[matched-1];
                }
            }
        }
        cout << 2 * m - matched << '\n';
    }
    return 0;
}
