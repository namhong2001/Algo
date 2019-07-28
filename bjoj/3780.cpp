#include <iostream>
#include <vector>
#include <numeric>

using namespace std; 

typedef pair<int,int> pii;

const int MOD = 1000; 

vector<int> r;
vector<int> cost;
int f(int a) { 
	if (a == r[a]) return a;
	int parent = r[a];
	int root = f(r[a]);
	cost[a] += cost[parent];
	r[a] = root;
	return root;
}

void u(int a, int b) {
	a = f(a); 
	r[a] = b;
	cost[a] += abs(b-a)%MOD;
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		r.resize(N); 
		iota(r.begin(), r.end(), 0);
		cost.assign(N, 0);
		while (true) {
			string s;
			cin >> s;
			if (s == "O") break;
			if (s == "E") {
				int a;
				cin >> a;
				a--;
				f(a);
				cout << cost[a] << '\n';
			} else if (s == "I") {
				int a, b;
				cin >> a >> b;
				a--, b--;
				u(a, b);
			}
		}
	}
	return 0;
}
