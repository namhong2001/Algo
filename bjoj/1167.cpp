#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <functional>


using namespace std;

const int N_MAX = 100000;
int weight[N_MAX+1][N_MAX+1];

struct Node {
    int label;
    Node* parent;
    vector<Node*> children;
    int height = -1;

    int getHeight() {
        if (height != -1) return height;

        height = 0;
        for (int i=0; i<children.size(); ++i) {
            Node* child = children[i];
            height = max(height, child->getHeight()+weight[label][child->label);
        }
        return height;
    }
};


bool isIn(const Node* a, const Node* b) {
    int dist = pow(abs(a->x - b->x), 2) + pow(abs(a->y - b->y), 2);
    return pow(a->r, 2) > dist;
}

Node* makeTree(Node* root, const vector<Node*> &circles) {
    vector<Node*> children;
    vector<vector<Node*>> descendants;
    for (int i=0; i<circles.size(); ++i) {
        Node* target = circles[i];
        bool inserted = false;
        for (int j=0; j<children.size(); ++j) {
            if (isIn(children[j], target)) {
                descendants[j].push_back(target);
                inserted = true;
                break;
            }
        }
        if (!inserted) {
            target->parent = root;
            children.push_back(target);
            descendants.push_back({}); // check necessary
        }
    }
    root->children = children;
    for (int i=0; i<children.size(); ++i) {
        makeTree(children[i], descendants[i]);
    }
    return root;
}

int solve(Node* root) {
    vector<Node*> &children = root->children;

    int ans = 0;
    vector<int> heights;
    for (int i=0; i<children.size(); ++i) {
        ans = max(ans, solve(children[i]));
        heights.push_back(children[i]->getHeight());
    }
    sort(heights.begin(), heights.end(), greater<int>());
    if (heights.size() >= 2) {
        ans = max(ans, heights[0] + heights[1] + 2);
    } else if (heights.size() == 1) {
        ans = max(ans, heights[0]+1);
    }

    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<Node> nodes(n+1);
    for (int i=0; i<n; ++i) {
        int nodeLabel;
        cin >> nodeLabel;
        Node &node =



        circles.push_back(Node);
    }
    sort(circles.begin(), circles.end(), [](const Node* A, const Node* B){return A->r > B->r;});
    Node* root = makeTree(circles.front(), vector<Node*>(circles.begin()+1, circles.end()));
    cout << solve(root) << endl;
}
