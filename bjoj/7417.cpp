#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<vector<bool>> adj(n, vector<bool>(n, false));
	for (int i=0; i<n; ++i) {
		while (true) {
			int a;
			cin >> a;
			if (a == 0) break;
			a--;
			adj[i][a] = true;
		}
	}
	unordered_set<int> A, B;
	for (int i=0; i<n; ++i) {
		bool know_all_A = true;
		for (int a : A) {
			if (adj[i][a] && adj[a][i]) continue;
			else {
				know_all_A = false;
				break;
			}
		}
		if (know_all_A) A.insert(i); 
		else {
			bool know_all_B = true;
			for (int b : B) {
				if (adj[i][b] && adj[b][i]) continue;
				else {
					know_all_B = false;
					break;
				}
			}
			if (know_all_B) B.insert(i);
			else {
				for (int a : A) cerr << a << ' ';
				cerr << endl;
				for (int b : B) cerr << b << ' ';
				cerr << endl;
				for (int k=0; k<n; ++k) {
					if (adj[i][k] && adj[k][i]) {
						cerr << k << ' ' ;
					}
				}
				cerr << endl;
				cerr << i << endl;
				cout << "No solution" << endl;
				return 0;
			}
		}
	}
	vector<int> can_B;
	for (int a : A) {
		bool know_all_B = true;
		for (int b : B) {
			if (adj[a][b] && adj[b][a]) {
				continue;
			} else {
				know_all_B = false;
				break;
			}
		}
		if (know_all_B) {
			can_B.push_back(a); 
		}
	} 
	for (int a : can_B) {
		if (A.size() > B.size()) {
			A.erase(a);
			B.insert(a);
		}
	}
	cout << A.size() << ' ';
	for (int a : A) {
		cout << a+1 << ' ';
	}
	cout << endl;
	cout << B.size() << ' ';
	for (int b : B) {
		cout << b+1 << ' ';
	}
	return 0;
} 
