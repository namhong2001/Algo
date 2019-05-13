#include <bits/stdc++.h>

using namespace std;

char board[1001][1001];
string words[1001];
tuple<int, int, char> ans[1001];

int toNumber(const char& c) {
    return c - 'A';
}

struct TrieNode {
    vector<TrieNode*> children;
    vector<int> outputs;
    int terminal = -1;
    TrieNode* fail = nullptr;

    TrieNode(): children(26, 0) {}
    ~TrieNode() {
        for (auto child : children) {
            if (child) delete child;
        }
    }

    void insert(const char* key, int id) {
        if (!*key) {
            terminal = id;
            return;
        }
        int next = toNumber(*key);

        if (!children[next]) {
            children[next] = new TrieNode();
        }
        children[next]->insert(key+1, id);
    }
};

void computeFailFunc(TrieNode* root) {
    queue<TrieNode*> q;
    q.push(root);
    root->fail = root;
    while (!q.empty()) {
        TrieNode* here = q.front();
        q.pop();
        for (int i=0; i<26; ++i) {
            TrieNode* child = here->children[i];
            if (!child) continue;

            if (here == root) {
                child->fail = root;
            }
            TrieNode* t = here;
            while (t != root && !t->children[i]) {
                t = t -> fail;
            }
            if (t->children[i]) t = t->children[i];
            child->fail = t;
            child->outputs = child->fail->outputs;
            if (child->terminal != -1) {
                child->outputs.push_back(child->terminal);
            }
            q.push(child);
        }
    }
}


int main() {
    int l, c, w;
    cin >> l >> c >> w;
    for (int i=0; i<l; ++i) {
        cin >> board[i];
    }
    TrieNode* root = new TrieNode();
    for (int i=0; i<w; ++i) {
        cin >> words[i];
        root->insert(words[i].c_str(), i);
        cout << words[i] << endl;
    }
    computeFailFunc(root);






    delete root;
    return 0;
}
