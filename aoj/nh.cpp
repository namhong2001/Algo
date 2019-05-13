#include <bits/stdc++.h>

using namespace std;

const int ALPHABETS = 26;
const int MOD = 10007;
int cache[101][1001];

int toNumber(const char& ch) {
    return ch - 'a';
}

struct TrieNode {
    vector<TrieNode*> children;
    vector<int> output;
    vector<TrieNode*> next;
    int terminal = -1;
    TrieNode* fail = NULL;
    int no = -1;

    TrieNode(): children(ALPHABETS, 0), next(ALPHABETS, 0) {}
    ~TrieNode() {
        for (int i=0; i<ALPHABETS; ++i) {
            if (children[i] != NULL) {
                delete(children[i]);
            }
        }
    };

    void insert(const char* key, int id) {
        if (*key == 0) {
            terminal = id;
            return;
        };
        int next = toNumber(*key);
        if (children[next] == NULL) {
            children[next] = new TrieNode();
        }
        children[next]->insert(key+1, id);
    }

    TrieNode* find(const char* key) {
        if (*key == 0) return this;
        int next = toNumber(*key);
        if (children[next] == NULL) return NULL;
        return children[next]->find(key+1);
    }
};

void computeFailFunc(TrieNode* root) {
    queue<TrieNode*> q;
    root->fail = root;
    q.push(root);
    while(!q.empty()) {
        TrieNode* here = q.front();
        q.pop();
        for(int edge = 0; edge < ALPHABETS; ++edge) {
            TrieNode* child = here->children[edge];
            if (!child) continue;
            if (here == root) {
                child->fail = root;
            }
            else {
                TrieNode* t = here->fail;
                while (t != root && t->children[edge] == NULL) {
                    t = t->fail;
                }
                if (t->children[edge]) t = t->children[edge];
                child->fail = t;
            }
            child->output = child->fail->output;
            if (child->terminal != -1) {
                child->output.push_back(child->terminal);
            }
            q.push(child);
        }
    }
}

int count(int length, TrieNode* state) {
    if (state->output.size()) return 0;
    if (length == 0) return 1;
    int& ret = cache[length][state->no];
    if (ret != -1) return ret;
    ret = 0;
    for (int letter=0; letter < ALPHABETS; ++letter) {
        ret += count(length-1, state->next[letter]);
        ret %= MOD;
    }
    return ret;
}

void computeTransition(TrieNode* here, int& nodeCounter) {
    here->no = nodeCounter++;
    for (int chr = 0; chr < ALPHABETS; ++chr) {
        TrieNode* next = here;
        while (next != next->fail && next->children[chr] == NULL) {
            next = next->fail;
        }
        if (next->children[chr]) next = next->children[chr];

        here->next[chr] = next;
        if (here->children[chr]) {
            computeTransition(here->children[chr], nodeCounter);
        }
    }
}

int main() {
    int c;
    cin >> c;
    while (c--) {
        int n, m;
        cin >> n >> m;
        memset(cache, -1, sizeof(cache));
        TrieNode *root = new TrieNode();
        vector<string> needles(m);
        int counter = 0;
        for (int i=0; i<m; ++i) {
            cin >> needles[i];
            root->insert(needles[i].c_str(), i);
        }
        computeFailFunc(root);
        computeTransition(root, counter);
        cout << count(n, root) << endl;
    }
    return 0;
}
