#include <bits/stdc++.h>

using namespace std;

const int ALPHA = 26;

int toNumber(char c) {
    return c - 'A';
}

struct Trie {
    Trie* children[ALPHA];
    char suggestStr[11] = {0};
    int suggestWeight = 0;

    Trie() {
        memset(children, 0, sizeof(children));
    }
    ~Trie() {
        for (int i=0; i<ALPHA; ++i) {
            delete children[i];
            delete suggestStr;
        }
    }

    Trie* find(const char* str) {
        if (str == nullptr) return this;
        return children[toNumber(*str)]->find(str+1);
    }

    void insert(const char* str, int weight) {
        if (!this->suggestStr || weight > this->suggestWeight) {
            strcpy(this->suggestStr, str);
            this->suggestWeight = weight;
        }


        if (str == nullptr) return;

        int cNum = toNumber(*str);
        if (!children[cNum]) {
            children[cNum] = new Trie();
        }
        children[cNum]->insert(str+1, weight);
    }

    int getTypeSaving(const char* str) {
        if (strcmp(str, this->suggestStr) == 0 || str == nullptr) {
            return strlen(str);
        }
        return this->children[toNumber(*str)]->getTypeSaving(str+1);
    }
};




int main() {
    int c;
    cin >> c;
    while (c--) {
        int n, m;
        cin >> n >> m;
        Trie root;
        for (int i=0; i<n; ++i) {
            char str[11];
            int weight;
            cin >> str >> weight;
            root.insert(str, weight);
        }
        int ans = 0;
        for (int i=0; i<m; ++i) {
            char str[11];
            cin >> str;
            ans += strlen(str) - root.getTypeSaving(str);
        }
        ans += m-1;
        cout << ans << endl;
    }
    return 0;
}
