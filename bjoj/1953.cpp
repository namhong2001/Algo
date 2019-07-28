#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

vector<int> A, B; 
int N;
bool checked[100];
bool hate[100][100];
void check(int here, bool is_a) {
	if (checked[here]) return;
	checked[here] = true; 
	if (is_a) A.push_back(here);
	else B.push_back(here);
	for (int there=0; there<N; ++there) {
		if (hate[here][there]) {
			check(there, !is_a);
		}
	}
} 

int main() {
	cin >> N;
	for (int i=0; i<N; ++i) {
		int C;
		cin >> C;
		for (int j=0; j<C; ++j) {
			int a;
			cin >> a;
			a--;
			hate[i][a] = hate[a][i] = true;
		}
	}
	for (int i=0; i<N; ++i) {
		if (A.empty()) check(i, true);
		else check(i, false);
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end()); 
	cout << A.size() << '\n';
	for (auto a : A) cout << a+1 << ' ';
	cout << '\n' << B.size() << '\n';
	for (auto b : B) cout << b+1 << ' ';
	return 0;
} 
