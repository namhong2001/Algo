#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>

using namespace std;

int toNumber(const char& c) {
    return c - 'a';
}

char toChar(const int& n) {
    return n + 'a';
}

void dfs(bool adj[26][26], bool visited[26], int me, vector<int> &ans) {
    visited[me] = true;
    for (int i=0; i<26; ++i) {
        if (adj[me][i] && !visited[i]) {
            dfs(adj, visited, i, ans);
        }
    }
    ans.push_back(me);
}

vector<int> dfsAll(bool adj[26][26]) {
    bool visited[26];
    memset(visited, false, 26);
    vector<int> ans;
    for (int i=0; i<26; ++i) {
        if (!visited[i]) {
            dfs(adj, visited, i, ans);
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

bool isValid(bool adj[26][26], vector<int> &ans) {
    bool isPrior[26];
    memset(isPrior, false, 26);
    for (int i=0; i<26; ++i) {
        int me = ans[i];
        for (int j=0; j<26; ++j) {
            if (adj[me][j] && isPrior[j]) return false;
        }
        isPrior[me] = true;
    }
    return true;
}

int main() {
    int c;
    cin >> c;
    while (c--) {
        int n;
        cin >> n;
        bool adj[26][26];
        memset(adj, 0, sizeof(adj));
        string prevS = "";
        while (n--) {
            string s;
            cin >> s;
            if (prevS != "") {
                for (int i=0; i<prevS.size() && i<s.size(); ++i) {
                    if (prevS[i] != s[i]) {
                        int prior = toNumber(prevS[i]);
                        int later = toNumber(s[i]);
                        adj[prior][later] = true;
                        break;
                    }
                }
            }
            prevS = s;
        }
        vector<int> ans = dfsAll(adj);
        if (isValid(adj, ans)) {
            for (int order : ans) {
                cout << toChar(order);
            }
        } else {
            cout << "INVALID HYPOTHESIS";
        }
        cout << '\n';
    }
    return 0;
}
