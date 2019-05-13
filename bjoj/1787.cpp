#include <iostream>
#include <vector>

using namespace std;

vector<int> getMinPi(const string& N) {
    int m = N.size();
    vector<int> pi(m, 0);
    int matched = 0;
    for (int i=1; i<m; ++i) {
        while(matched > 0 && N[i] != N[matched]) {
            matched = pi[matched-1];
        }
        if(N[i] == N[matched]) {
            ++matched;
            int minM = matched;
            while(pi[minM-1] > 0) {
                minM = pi[minM-1];
            }
            pi[i] = minM;
        }
    }
    return pi;
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> pi = getMinPi(s);
    long long int sum = 0;
    for (int i=0; i<pi.size(); ++i) {
        int minpi = pi[i];
        if (minpi == 0) {
            continue;
        }
        sum += i + 1 - minpi;
    }
    cout << sum;
}
