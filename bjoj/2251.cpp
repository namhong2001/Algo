#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

bool visited[201][201][201];

int A, B, C;

void search(int a, int b, int c) {
	if (a<0 || b<0 || c<0 || a>A || b>B || c>C || visited[a][b][c]) return; 
	visited[a][b][c] = true;

	search(a-(B-b), B, c);
	search(a-(C-c), b, C);
	search(0, b+a, c);
	search(0, b, c+a);
	
	search(A, b-(A-a), c);
	search(a, b-(C-c), C);
	search(a+b, 0, c);
	search(a, 0, c+b);
	
	search(A, b, c-(A-a));
	search(a, B, C-(B-b));
	search(a+c, b, 0);
	search(a, b+c, 0); 
}

vector<int> solve() {
	vector<int> ret;
	memset(visited, false, sizeof(visited));
	search(0, 0, C); 
	for (int i=0; i<=B; ++i) {
		int j = C-i;
		if (j<0) break;
		if (visited[0][i][j]) ret.push_back(j);
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

int main() {
	cin >> A >> B >> C;
	vector<int> ans = solve();
	for (int a : ans) {
		cout << a << ' ';
	}
	return 0;
} 
