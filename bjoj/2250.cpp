#include <iostream>
#include <vector>

#include <utility>

using namespace std;

struct Node;

const int N_MAX = 10000;
vector<Node> nodes(N_MAX+1);

struct Node {
    int left = -1;
    int right = -1;
    int parent = -1;
    bool isLeft;
    int cnt = -1;
    int pos = -1;
    int getCnt() {
        if (cnt != -1) return cnt;

        cnt = 1;
        if (left != -1) cnt += nodes[left].getCnt();
        if (right != -1) cnt += nodes[right].getCnt();

        return cnt;
    }
    int getPos() {
        if (pos != -1) return pos;
        if (parent == -1) {
            pos = 1;
            if (left != -1) {
                pos += nodes[left].getCnt();
            }
            return pos;
        }

        if (isLeft) {
            pos = nodes[parent].getPos() - 1;
            if (right != -1) {
                pos -= nodes[right].getCnt();
            }
        } else {
            pos = nodes[parent].getPos() + 1;
            if (left != -1) {
                pos += nodes[left].getCnt();
            }
        }
        return pos;
    }
};


int findRoot() {
    for (int i=1; i<nodes.size(); ++i) {
        if (nodes[i].parent == -1) return i;
    }
    return -1;
}

pair<int, int> solve(int root) {
    pair<int, int> ret = {-1, -1};
    int curLevel = 1;
    vector<int> A, B;
    vector<int> *curLevelNodes = &A;
    vector<int> *nextLevelNodes = &B;
    curLevelNodes->push_back(root);

    while(!curLevelNodes->empty()) {
        for (int i=0; i<curLevelNodes->size(); ++i) {
            Node &node = nodes[(*curLevelNodes)[i]];
            if (node.left != -1) nextLevelNodes->push_back(node.left);
            if (node.right != -1) nextLevelNodes->push_back(node.right);
        }
        Node &leftMost = nodes[curLevelNodes->front()];
        Node &rightMost = nodes[curLevelNodes->back()];
        int width = rightMost.getPos() - leftMost.getPos() + 1;
        if (width > ret.second) {
            ret = {curLevel, width};
        }

        swap(curLevelNodes, nextLevelNodes);
        nextLevelNodes->clear();
        curLevel++;
    }
    return ret;
}

int main() {
    int n;
    cin >> n;
    for (int i=0; i<n; ++i) {
        int me, left, right;
        cin >> me >> left >> right;
        nodes[me].left = left;
        nodes[me].right = right;
        if (left != -1) {
            nodes[left].parent = me;
            nodes[left].isLeft = true;
        }
        if (right != -1) {
            nodes[right].parent = me;
            nodes[right].isLeft = false;
        }
    }
    int root = findRoot();
    pair<int, int> ans = solve(root);
    cout << ans.first << ' ' << ans.second;
    return 0;
}
