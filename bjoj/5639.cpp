#include <iostream>

using namespace std;
const int INF = 987654321;

struct Node {
    int key;
    Node* parent;
    Node* left;
    Node* right;
    Node(const int key): key(key), left(nullptr), right(nullptr), parent(nullptr) {}
};

Node* insert(Node* root, int num) {
    if (root == nullptr) return new Node(num);

    if (num < root->key) root->left = insert(root->left, num);
    else root->right = insert(root->right, num);
    return root;
}

void printPostOrder(Node* root) {
    if (root == nullptr) return;

    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->key << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    Node* root = nullptr;
    while (cin >> n) {
        root = insert(root, n);
    }
    printPostOrder(root);

    return 0;
}
