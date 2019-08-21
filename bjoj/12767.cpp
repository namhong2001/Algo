#include <iostream>
#include <set>

using namespace std;

struct Node {
	int val;
	Node* left = nullptr;
	Node* right = nullptr; 
	Node(int val): val(val) {}; 
	void add(int a) { 
		Node* &target = a < val ? left : right;
		if (target) target->add(a);
		else target = new Node(a);
	} 
	void signature(string& sig) {
		if (left == nullptr) {
			sig.push_back('0');
		} else {
			sig.push_back('1');
			left->signature(sig);
		}
		if (right == nullptr) {
			sig.push_back('0');
		} else {
			sig.push_back('2');
			right->signature(sig);
		}
	} 
};

int main() {
	int N, K;
	cin >> N >> K;
	set<string> sigs;
	for (int i=0; i<N; ++i) { 
		Node* root = nullptr;
		for (int j=0; j<K; ++j) {
			int a;
			cin >> a;
			if (j == 0) {
				root = new Node(a);
			} else {
				root->add(a); 
			}
		} 
		string sig;
		root->signature(sig);
		sigs.insert(sig);
	} 
	cout << sigs.size() << endl;
	return 0;
}

