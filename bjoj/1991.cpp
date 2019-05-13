#include <iostream>
#include <vector>

using namespace std;

struct Node {
    string label;
    Node* parent = nullptr;
    Node* left = nullptr;
    Node* right = nullptr;
};

void printPreorder(const Node* node) {
    if (node == nullptr) return;

    cout << node->label;
    printPreorder(node->left);
    printPreorder(node->right);
}

void printInorder(const Node* node) {
    if (node == nullptr) return;

    printInorder(node->left);
    cout << node->label;
    printInorder(node->right);
}

void printPostorder(const Node* node) {
    if (node == nullptr) return;

    printPostorder(node->left);
    printPostorder(node->right);
    cout << node->label;
}

const int N_MAX = 26;

int main() {
    int n;
    cin >> n;
    vector<Node> nodes(N_MAX);
    for (int i=0; i<n; ++i) {
        string targetLabel, leftLabel, rightLabel;
        cin >> targetLabel >> leftLabel >> rightLabel;
        Node* target = &nodes[targetLabel[0] - 'A'];
        target->label = targetLabel;
        Node* left = nullptr;
        Node* right = nullptr;
        if (leftLabel != ".") {
            left = &nodes[leftLabel[0]-'A'];
            left->parent = target;
        }
        if (rightLabel != ".") {
            right = &nodes[rightLabel[0]-'A'];
            right->parent = target;
        }
        target->left = left;
        target->right = right;
    }
    printPreorder(&nodes[0]);
    cout << endl;
    printInorder(&nodes[0]);
    cout << endl;
    printPostorder(&nodes[0]);
    cout << endl;
    return 0;
}
