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


int main() {
    string h;
    string n;
    getline(cin, h);
    getline(cin, n);
    vector<int> kmp = kmpSearch(h, n);
    cout << kmp.size() << '\n';
    for (auto i : kmp) {
        cout << i + 1 << ' ';
    }
    return 0;
}
