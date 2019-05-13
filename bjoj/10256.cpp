#include <bits/stdc++.h>

using namespace std;

const int CHAR_CNT = 4;

int toNumber(const char c) {
    if (c == 'A') return 0;
    if (c == 'G') return 1;
    if (c == 'T') return 2;
    if (c == 'C') return 3;
    return -1;
}


struct TrieNode {
    vector<TrieNode*> children;
    bool terminal = false;
    TrieNode* fail = nullptr;

    TrieNode(): children(CHAR_CNT, 0) {}
    ~TrieNode() {
        for (TrieNode* child : children) {
            if (child) delete child;
        }
    }

    void insert (const char* key) {
        if(!*key) {
            terminal = true;
            return;
        }
        int next = toNumber(*key);
        if (!children[next]) {
            children[next] = new TrieNode();
        }
        children[next]->insert(key+1);
    }
};

void computeFailFunc(TrieNode* root) {
    queue<TrieNode*> q;
    q.push(root);
    root->fail = root;
    while (!q.empty()) {
        TrieNode* here = q.front();
        q.pop();

        for (int i=0; i<CHAR_CNT; ++i) {
            TrieNode* child = here->children[i];
            if (!child) continue;

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
            q.push(child);
        }
    }
}

int solve(string& s, TrieNode* root) {
    int ret = 0;
    TrieNode* state = root;
    for (int i=0; i<s.size(); ++i) {
        int next = toNumber(s[i]);
        while (state != root && !state->children[next]) {
            state = state->fail;
        }
        if (state->children[next]) state = state->children[next];
        if (state->terminal) ++ret;
    }
    return ret;
}

bool isMirror(char* key, int start, int end) {
    while (start < end-1) {
        if (*(key+start) != *(key+end-1)) return false;
        start++;
        end--;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int c;
    cin >> c;
    while (c--) {
        int n, m;
        cin >> n >> m;
        string hay, needle;
        cin >> hay >> needle;
        TrieNode* root = new TrieNode();

        char cstr[101];
        strcpy(cstr, needle.c_str());
        root->insert(cstr);

        for (int i=0; i<needle.size(); ++i) {
            for (int j=i+2; j<=needle.size(); ++j) {
                if (isMirror(cstr, i, j)) continue;

                reverse(cstr+i, cstr+j);
                root->insert(cstr);
                reverse(cstr+i, cstr+j);
            }
        }
        computeFailFunc(root);
        cout << solve(hay, root) << '\n';

        delete root;
    }

    return 0;
}
