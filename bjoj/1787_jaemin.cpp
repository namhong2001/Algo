#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

vector<int> getPartialMatch(const string& N) {
    int m = N.size();
    vector<int> pi(m, 0);
    int begin = 1, matched = 0;

    while(begin + matched < m) {
        if(N[begin + matched] == N[matched]) {
            ++matched;
            pi[begin + matched - 1] = matched;
        }
        else {
            if(matched == 0)
                ++begin;
            else {
                begin += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }
    return pi;
}

int main() {
    int n;
    cin >> n;
    char s[1000001];
    scanf("%s", s);
    vector<int> pi = getPartialMatch(s);
    vector<long long> P(pi.size());
    long long period = 0;
    long long piece = 0;
    bool isStart = false;
    for(int i=1; i<n; ++i) {
        if(!isStart && (pi[i]-pi[i-1])==1) {
            isStart = true;
            period = i;
            piece = i;
            P[i] = period;
        }
        else if(isStart && (pi[i]-pi[i-1])==1) {
            period = P[i-1];
            if(i % piece == 0) period += piece;
            P[i] = period;
        }
        else if(isStart && (pi[i] == 0)) {
            isStart = false;
            period = 0;
            piece = 0;
            P[i] = period;
        }
    }
    long long sum = 0;
    for(int i=0; i<n; ++i)
        sum += P[i];
    cout << sum << endl;
}
