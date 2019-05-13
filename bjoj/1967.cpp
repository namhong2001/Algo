#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

struct Node {
    int label;
    Node* parent = nullptr;
    vector<Node*> children;
    int height = -1;
    int weight;

    int getHeight() {
        if (height != -1) return height;

        height = 0;
        for (int i=0; i<children.size(); ++i) {
            Node* child = children[i];
            height = max(height, child->getHeight()+child->weight);
        }
        return height;
    }
};

int solve(Node* root) {
    vector<Node*> &children = root->children;
    int ans = 0;
    vector<int> heights;
    for (int i=0; i<children.size(); ++i) {
        ans = max(ans, solve(children[i]));
        heights.push_back(children[i]->getHeight()+children[i]->weight);
    }

    sort(heights.begin(), heights.end(), greater<int>());

    if (heights.size() >= 2) {
        ans = max(ans, heights[0] + heights[1]);
    } else if (heights.size() == 1) {
        ans = max(ans, heights[0]);
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<Node> nodes(n+1);
    for (int i=0; i<n-1; ++i) {
        int nodeIdx, childIdx, weight;
        cin >> nodeIdx >> childIdx >> weight;
        Node* node = &nodes[nodeIdx];
        Node* child = &nodes[childIdx];
        node->label = nodeIdx;
        node->children.push_back(child);
        child->label = childIdx;
        child->parent = node;
        child->weight = weight;
    }

    cout << solve(&nodes[1]) << endl;

    return 0;
}

