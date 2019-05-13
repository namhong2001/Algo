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
    int l;
    cin >> l;
    string s;
    cin >> s;
    vector<int> pi = getPartialMatch(s);
    cout << l - pi[l-1];
    return 0;
}
