#include <bits/stdc++.h>

using namespace std;

const int MAX_WORDS = 300000;

const int ALPHA = 26;
int toNumber(const char c) {
    return c - 'A';
}

vector<string> words;
vector<bool> found;
char board[4][4];
bool visited[4][4];
int navigate[3] = {-1, 0, 1};


struct TrieNode {
    vector<TrieNode*> children;
    int terminal = -1;
    TrieNode(): children(ALPHA, 0) {}

    void insert(const char *key, const int id) {
        if(!*key) {
            terminal = id;
            return ;
        }
        int next = toNumber(*key);
        if (children[next] == NULL) {
            children[next] = new TrieNode();
        }
        children[next]->insert(key+1, id);
    }
};

void solve(int i, int j, TrieNode* state) {
    if (state->terminal != -1) {
        found[state->terminal] = true;
    }

    if (i<0 || i>3 || j<0 || j>3) return;
    if (visited[i][j]) return;

    char c = board[i][j];
    int next = toNumber(c);
    if (state->children[next] == NULL) return;


    visited[i][j] = true;
    for (int a : navigate) {
        for (int b : navigate) {
            if (a == 0 && b == 0) continue;
            solve(i+a, j+b, state->children[next]);
        }
    }
    visited[i][j] = false;
}

int getScore(int wordIndex) {
    switch(words[wordIndex].size()) {
    case 1:
    case 2:
        return 0;
    case 3:
    case 4:
        return 1;
    case 5:
        return 2;
    case 6:
        return 3;
    case 7:
        return 5;
    case 8:
        return 11;
    default:
        return 0;
    }
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    int w;
    cin >> w;
    words = vector<string>(w);
    TrieNode root;
    for (int i=0; i<w; ++i) {
        cin >> words[i];
        root.insert(words[i].c_str(), i);
    }

    int n;
    cin >> n;
    while(n--) {
        // init
        found = vector<bool>(w);
        for (int i=0; i<4; ++i) {
            for (int j=0; j<4; ++j) {
                cin >> board[i][j];
            }
        }
        for (int i=0; i<4; ++i) {
            for (int j=0; j<4; ++j) {
                memset(visited, false, sizeof(visited));
                solve(i, j, &root);
            }
        }
        int score = 0;
        int longestWordIndex = -1;
        int longestWordSize = -1;
        int foundWordCount = 0;

        for (int i=0; i<w; ++i) {
            if (found[i]) {
                ++foundWordCount;
                score += getScore(i);
                if ((int)words[i].size() > longestWordSize) {
                    longestWordSize = words[i].size();
                    longestWordIndex = i;
                } else if ((int)words[i].size() == longestWordSize && words[i] < words[longestWordIndex]) {
                    longestWordIndex = i;
                }
            }
        }
        cout << score << ' ' << words[longestWordIndex] << ' ' << foundWordCount << endl;
    }

    return 0;
}
