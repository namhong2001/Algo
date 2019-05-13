#include <iostream>
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


int main() {

    while(true) {
        string s;
        cin >> s;
        if (s == ".") break;
        vector<int> pi = getPartialMatch(s);
        int plen = pi[s.size()-1];
        int alen = s.size() - plen;
        int n;
        if (s.size() % alen) {
            n = 1;
        } else {
            n = s.size() / alen;
        }
        cout << n << '\n';
    }

    return 0;
}
