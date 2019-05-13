#include <bits/stdc++.h>

using namespace std;

void makeTree(int tree[], int index, int max) {
    if (index > max) return;
    makeTree(tree, index*2, max);
    cin >> tree[index];
    makeTree(tree, index*2+1, max);
}

int main() {
    int k;
    cin >> k;
    int tree[1<<k];
    memset(tree, -1, sizeof(tree));
    makeTree(tree, 1, (1<<k)-1);
    int p = 1;
    for (int i=0; i<k; ++i) {
        for (int j=0; j<(1<<i); ++j, ++p) {
            cout << tree[p] << ' ';
        }
        cout << endl;
    }
    return 0;
}
