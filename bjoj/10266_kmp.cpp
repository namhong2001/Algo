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


int main() {
    const int MAX_A = 360000;
    char arr[MAX_A+1];
    char target[MAX_A+1];
    for (int i=0; i<MAX_A; ++i) {
        arr[i] = '0';
        target[i] = '0';
    }
    arr[MAX_A] = '\0';
    target[MAX_A] = '\0';
    int n;
    cin >> n;
    for (int i=0; i<n; ++i) {
        int a;
        scanf("%d", &a);
        arr[a] = '1';
    }
    for (int i=0; i<n; ++i) {
        int a;
        scanf("%d", &a);
        target[a] = '1';
    }
    string arr_s(arr);
    string target_s(target);
    if (kmpSearch(arr_s + arr_s, target_s).size()) {
        cout << "possible";
    } else {
        cout << "impossible";
    }

    return 0;
}
