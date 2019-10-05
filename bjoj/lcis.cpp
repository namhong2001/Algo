#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int INF = 987654321;


vector<int> lcis;

void trackback(int j, int last, int len, int B[], int L[]) {
	while (L[j] != len || last <= B[j]) j--;
	if (j > 0 && len > 0) {
		trackback(j, B[j], len-1, B, L);
		lcis[len] = B[j];
	}
} 

int main() {
	int N;
	cin >> N;
	int A[N+1];
	for (int i=1; i<=N; ++i) cin >> A[i];
	int M;
	cin >> M;
	lcis.resize(M+1);
	int B[M+1];
	for (int i=1; i<=M; ++i) cin >> B[i];
	
	int L[M+1] = {};
	int len = 0;
	for (int i=1; i<=N; ++i) {
		L[0] = 0;
		for (int j=1; j<=M; ++j) {
			if (A[i] > B[j] && L[0] < L[j]) L[0] = L[j];
			if (A[i] == B[j]) L[j] = L[0] + 1;
		}
		int new_len = *max_element(L+1, L+M+1);
		if (new_len > len) {
			len = new_len;
			trackback(M, INF, len, B, L);
		} 
	} 
	cout << len << endl; 
	for (int i=1; i<=len; ++i) {
		cout << lcis[i] << ' ';
	}
	return 0;
}

