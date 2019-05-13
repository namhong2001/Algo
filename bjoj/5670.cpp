#include <bits/stdc++.h>

using namespace std;

const int ALPHABETS = 26;

int ans = 0;
vector<string> words;

int toNumber(const char c) {
    return c - 'a';
}

struct TrieNode {
    vector<TrieNode*> children;
    int strId = -1;
    int matchCount = 0;
    TrieNode(): children(ALPHABETS, 0) {}
    ~TrieNode() {
        for (int i=0; i<ALPHABETS; ++i) {
            if(children[i]) {
                delete children[i];
            }
        }
    }

    void insert(int id, int pos) {
        if (words[id].size() == pos) return;

        int next = toNumber(words[id][pos]);
        if (children[next] == NULL) {
            TrieNode* child = new TrieNode();
            child->strId = id;
            child->matchCount = words[id].size() - pos;
            children[next] = child;
        } else {
            int i;
            bool fullMatch = true;
            int childStrId = children[next]->strId;
            for (i=0; i<children[next]->matchCount; ++i) {
                if (words[id].size() == pos+i || words[childStrId][pos+i] != words[id][pos+i]) {
                    fullMatch = false;
                    break;
                }
            }
            if (!fullMatch) {
                TrieNode* newChild = new TrieNode();
                newChild->strId = id;
                newChild->matchCount = i;
                int childNext = toNumber(words[childStrId][pos+i]);
                children[next]->matchCount -= i;
                newChild->children[childNext] = children[next];
                children[next] = newChild;
            }
        }

        children[next]->insert(id, pos + children[next]->matchCount);
    }
    TrieNode* find(int id, int pos) {
        if (words[id].size() == pos) return this;

        ++ans;
        int next = toNumber(words[id][pos]);
        return children[next]->find(id, pos + children[next]->matchCount);
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    while (cin >> n) {
        ans = 0;
        words = vector<string>(n);
        TrieNode root;
        for (int i=0; i<n; ++i) {
            cin >> words[i];
            root.insert(i, 0);
        }
        for (int i=0; i<n; ++i) {
            root.find(i, 0);
        }
        cout << fixed << setprecision(2) << (double)ans / n << endl;
    }
    return 0;
}
