#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std; 

vector<int> seq;
int N, S;
vector<int> A;
vector<int> B;
unordered_map<int,int> A_cnt;
unordered_map<int,int> B_cnt; 

void comb(int here, int sum, const vector<int> &origin, vector<int> &sums, unordered_map<int,int> &cnt) {
	for (int i=here; i<(int)origin.size(); ++i) {
		int nsum = sum + origin[i]; 
		if (cnt.find(nsum) == cnt.end()) {
			cnt[nsum] = 1;
			sums.push_back(nsum);
		} else {
			cnt[nsum]++;
		}
		comb(i+1, nsum, origin, sums, cnt);
	}
} 

void init() {
	int mid = seq.size()/2;
	comb(0, 0, vector<int>(seq.begin(), seq.begin()+mid), A, A_cnt);
	comb(0, 0, vector<int>(seq.begin()+mid, seq.end()), B, B_cnt);
} 

long long solve() { 
	init();
	long long ret = 0;
	for (int a : A) {
		if (B_cnt.find(S-a) != B_cnt.end()) {
			ret += 1ll * A_cnt[a] * B_cnt[S-a];
		}
	}
	for (int a : A) {
		if (a == S) ret += A_cnt[a];
	}
	for (int b : B) {
		if (b == S) ret += B_cnt[b];
	}
	return ret;
} 

int main() { 
	cin >> N >> S;
	seq.resize(N);
	for (int i=0; i<N; ++i) {
		cin >> seq[i];
	}
	cout << solve();
	return 0;
} 
