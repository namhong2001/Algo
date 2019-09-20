#include <iostream> 

using namespace std;

int main() {
	int N;
	cin >> N;
	bool arr[100][100] = {};
	for (int i=0; i<N; ++i) {
		int A, B;
		cin >> A >> B;
		for (int da=0; da<10; ++da) {
			for (int db=0; db<10; ++ db) {
				int a = A+da;
				int b = B+db;
				arr[a][b] = true;
			}
		}
	}
	int ans = 0;
	for (int i=0; i<100; ++i) {
		for (int j=0; j<100; ++j) {
			if (arr[i][j]) ans++;
		}
	} 
	cout << ans; 
	return 0;
}

