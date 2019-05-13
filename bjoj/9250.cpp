#include <bits/stdc++.h>

using namespace std;

const int ALPHA = 26;

int toNumber(const char c) {
    return c - 'a';
}

struct TrieNode {
    vector<TrieNode*> children;
    bool terminal = false;
    TrieNode* fail = nullptr;
    bool matched = false; // instead of outputs

    TrieNode(): children(ALPHA, 0) {}
    ~TrieNode() {
        for (TrieNode* child : children) {
            if (child) {
                delete child;
            }
        }
    }
    void insert(const char* key) {
        if (!*key) {
            terminal = true;
            return;
        }
        int next = toNumber(*key);
        if (children[next] == nullptr) {
            children[next] = new TrieNode();
        }
        children[next]->insert(key+1);
    }
};

void computeFailFunc(TrieNode* root) {
    queue<TrieNode*> q;
    q.push(root);
    while (!q.empty()) {
        TrieNode* here = q.front();
        q.pop();
        for (int i=0; i<ALPHA; ++i) {
            TrieNode* child = here->children[i];
            if (!child) continue;

            if (here == root) {
                child->fail = root;
            } else {
                TrieNode* t = here->fail;
                while (t != root && t->children[i] == nullptr) {
                    t = t->fail;
                }
                if (t->children[i]) {
                    t = t->children[i];
                }
                child->fail = t;
            }
            if (child->fail->matched || child->terminal) {
                child->matched = true;
            }

            q.push(child);
        }
    }
}

bool solve(const string& s, TrieNode* root) {
    TrieNode* state = root;
    for (int i=0; i<s.size(); ++i) {
        char c = s[i];
        int next = toNumber(c);
        while (state != root && state->children[next] == nullptr) {
            state = state->fail;
        }
        if (state->children[next]) state = state->children[next];
        if (state->matched) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    TrieNode* root = new TrieNode();
    while(n--) {
        string s;
        cin >> s;
        root->insert(s.c_str());
    }
    computeFailFunc(root);
    int q;
    cin >> q;
    while (q--) {
        string s;
        cin >> s;
        cout << (solve(s, root) ? "YES" : "NO") << '\n';
    }
//    delete root;
    return 0;
}
