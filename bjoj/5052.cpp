#include <bits/stdc++.h>

using namespace std;

int toNumber(const char c) {
    return c - '0';
}

struct TrieNode {
    vector<TrieNode*> children;
    bool terminal = false;
    TrieNode(): children(10, 0) {}
    ~TrieNode() {
        for (int i=0; i<10; ++i) {
            if (children[i]) delete children[i];
        }
    }

    bool insert(const char* key) {
        if (terminal) return false;

        if (!*key) {
            terminal = true;
            return true;
        }

        int next = toNumber(*key);

        if (children[next] == NULL) {
            children[next] = new TrieNode();
        }
        return children[next]->insert(key+1);
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        bool isConsistent = true;
        TrieNode root;
        vector<string> inputs[11];
        while (n--) {
            string s;
            cin >> s;
            inputs[s.size()].push_back(s);
        }
        for (int i=1; i<11; ++i) {
            for (string s : inputs[i]) {
                if (!root.insert(s.c_str())) {
                    isConsistent = false;
                }
            }
        }
        cout << (isConsistent ? "YES" : "NO") << endl;
    }
    return 0;
}
