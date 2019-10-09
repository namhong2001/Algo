#include <iostream>
#include <vector>

using namespace std;

int N, M;

bool solve(vector<vector<int>> &A, vector<vector<int>> &B) {
	for (int i=0; i<N; ++i) {
		int a = 0, b = 0; 
		for (int j=0; j<M; ++j) {
			a += A[i][j];
			b += B[i][j];
		}
		if (a%2 != b%2) return false;
	}
	for (int j=0; j<M; ++j) {
		int a = 0, b = 0; 
		for (int i=0; i<N; ++i) {
			a += A[i][j];
			b += B[i][j];
		}
		if (a%2 != b%2) return false;
	}
	return true;
}

int main() {
	cin >> N >> M;
	vector<vector<int>> A(N, vector<int>(M));
	vector<vector<int>> B(N, vector<int>(M));
	for (int i=0; i<N; ++i) {
		for (int j=0; j<M; ++j) {
			cin >> A[i][j];
		}
	}
	for (int i=0; i<N; ++i) {
		for (int j=0; j<M; ++j) {
			cin >> B[i][j];
		}
	}
	cout << (solve(A, B) ? "Yes" : "No"); 
	return 0;
}

