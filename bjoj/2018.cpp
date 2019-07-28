#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> psum;
	psum.push_back(0);
	for (int i=1; i<=N; ++i) {
		int next = psum[i-1] + i;
		if (next > N) break;
		psum.push_back(next);
	}
	int cnt = 0;
	for (int i=1; i<(int)psum.size(); ++i) {
		int sum = psum[i]; 
		if ((N-sum)%i == 0) cnt++;
	}
	cout << cnt << endl;
	return 0;
}

		
