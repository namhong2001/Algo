#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 987654321; 

int DNA_to_num(char dna) {
	if (dna == 'A') return 0;
	else if (dna == 'C') return 1;
	else if (dna == 'G') return 2;
	else if (dna == 'T') return 3;
}

char num_to_DNA(int num) {
	if (num == 0) return 'A';
	else if (num == 1) return 'C';
	else if (num == 2) return 'G';
	else if (num == 3) return 'T';
} 

int main() {
	int n, m;
	cin >> n >> m;
	int cnt[m][4]; 
	memset(cnt, 0, sizeof(cnt));
	vector<string> inputs(n);
	for (int i=0; i<n; ++i) {
		cin >> inputs[i];
		for (int j=0; j<m; ++j) {
			cnt[j][DNA_to_num(inputs[i][j])]++; 
		} 
	}
	int dist = 0;
	string ans;
	for (int i=0; i<m; ++i) { 
		int max_cnt = 0;
		int index = 0;
		for (int j=0; j<4; ++j) { 
			if (cnt[i][j] > max_cnt) {
				max_cnt = cnt[i][j];
				index = j;
			}
		} 
		dist += n - max_cnt;
		ans += num_to_DNA(index); 
	}
	cout << ans << endl;
	cout << dist << endl;
	return 0;
} 
