#include <bits/stdc++.h>

using namespace std;

struct TrieNode {
    vector<TrieNode*> children;
    bool terminal = false;
    TrieNode* fail = nullptr;
    bool matched = false;

    TrieNode(): children(128, 0) {}
    ~TrieNode() {
        for (TrieNode* child :  children) {
            if (child) delete child;
        }
    }

    void insert(const char* key) {
        if (!*key) {
            terminal = true;
            return;
        }
        if (!children[*key]) {
            children[*key] = new TrieNode();
        }
        children[*key]->insert(key+1);
    }
};

void computeFailFunc(TrieNode* root) {
    queue<TrieNode*> q;
    q.push(root);
    root->fail = root;
    while (!q.empty()) {
        TrieNode* here = q.front();
        q.pop();
        for (int i=0; i<128; ++i) {
            if (!here->children[i]) continue;
            TrieNode* child = here->children[i];
            if (here == root) {
                child->fail = root;
            } else {
                TrieNode* t = here->fail;
                while (t != root && !t->children[i]) {
                    t = t->fail;
                }
                if (t->children[i]) t = t->children[i];
                child->fail = t;
            }
            child->matched = child->fail->matched || child->terminal;
            q.push(child);
        }
    }
}


int solve(string& s, TrieNode* root) {
    TrieNode* state = root;
    int ret = 0;
    for (int i=0; i<s.size(); ++i) {
        int c = s[i];
        while (state != root && !state->children[c]) {
            state = state->fail;
        }
        if (state->children[c]) state = state->children[c];
        if (state->matched) {
            ++ret;
            state=root;
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while (true) {
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0) break;

        TrieNode* root = new TrieNode();


        for (int i=0; i<n; ++i) {
            string s;
            cin >> s;
            root->insert(s.c_str());
        }
        computeFailFunc(root);

        int ans = 0;
        for (int i=0; i<m+1; ++i) {
            string s;
            getline(cin, s);
            if (i==0) continue;
            ans += solve(s, root);
        }
        cout << ans << '\n';
        delete root;
    }
    return 0;
}
