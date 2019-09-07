#include <iostream>
#include <vector>

using namespace std;

const int INF = 987654321;

int N, M; 
vector<int> arr(101);
int d[101][101]; 

int solve(int start, int M) {
	if (M == 0) return 0;
	if (start >= N) return -INF+1; 
	int &ret = d[start][M]; 
	if (ret != -INF) return ret;
	ret = -INF + 1;
	int sum = 0;
	for (int i=start; i<N; ++i) {
		sum += arr[i];
		ret = max(ret, sum + solve(i+2, M-1));
	}
	ret = max(ret, solve(start+1, M));
	return ret; 
}
	
	
	

int main() {
	for (int i=0; i<101; ++i) {
		for (int j=0; j<101; ++j) {
			d[i][j] = -INF;
		}
   	} 
	cin >> N >> M;
	for (int i=0; i<N; ++i) {
		cin >> arr[i];
	}
	cout << solve(0, M); 
    return 0;
}

