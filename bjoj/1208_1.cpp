#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std; 

vector<int> seq;
int N, S;
vector<int> A;
vector<int> B;
unordered_map<int,int> A_cnt;
unordered_map<int,int> B_cnt; 

void init() {
	int mid = seq.size()/2;
	vector<int> left(seq.begin(), seq.begin()+mid);
	vector<int> right(seq.begin()+mid, seq.end());
	for (int i=1; i<1<<left.size(); ++i) {
		int s = 0;
		for (int j=0; j<(int)left.size(); ++j) {
			if (i & 1<<j) s += left[j];
		}
		if (A_cnt.find(s) == A_cnt.end()) {
			A_cnt[s] = 1;
			A.push_back(s);
		} else {
			A_cnt[s]++;
		}
	}
	for (int i=1; i<1<<right.size(); ++i) {
		int s = 0;
		for (int j=0; j<(int)right.size(); ++j) {
			if (i & 1<<j) s += right[j];
		}
		if (B_cnt.find(s) == B_cnt.end()) {
			B_cnt[s] = 1;
			B.push_back(s);
		} else {
			B_cnt[s]++;
		}
	} 
	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), greater<int>()); 
} 

long long solve() { 
	init();
	int ai = 0;
	int bi = 0;
	long long ret = 0;
	while (ai < (int)A.size() && bi < (int)B.size()) {
		int a = A[ai];
		int b = B[bi];
		int s = a + b;
		if (s == S) {
			ret += 1ll * A_cnt[a] * B_cnt[b];
			ai++, bi++;
		}
		else if (s > S) bi++;
		else ai++;
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
