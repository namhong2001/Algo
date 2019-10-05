#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

const ll INF = 987654321987;

int N, M;
int d[501][501];
vector<int> A, B;

void trackback(int n, int m, int len, ll last) { 
	//cerr << "{" << n << ", " << m << ", " << len << ", " << last << "}" << endl;
	if (len == 0) return;
	for (int j=m; j>=0; --j) { 
		//if (d[n][j] == len) cerr << n << " " << j << " " << B[j] << endl;
		if (d[n][j] == len && (ll)B[j] < last) { 
			while (d[n][j] == len) n--;
			trackback(n, j-1, len-1, B[j]);
			cout << B[j] << ' ';
			break;
		}
	}
} 

int main() { 
	cin >> N;
	A.resize(N+1);
	for (int i=1; i<=N; ++i) cin >> A[i];
	cin >> M;
	B.resize(M+1);
	for (int i=1; i<=M; ++i) cin >> B[i];

	for (int i=1; i<=N; ++i) {
		int max_prefix = 0;
		for (int j=1; j<=M; ++j) { 
			d[i][j] = d[i-1][j];
			if (A[i] == B[j]) d[i][j] = max_prefix+1;
			if (A[i] > B[j]) max_prefix = max(max_prefix, d[i-1][j]);
		}
	}
	int len = *max_element(d[N]+1, d[N]+M+1); 
	cout << len << '\n';
	trackback(N, M, len, INF); 
	return 0;
}

