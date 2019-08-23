#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int A, B;
	cin >> A >> B;
	int N;
	cin >> N;
	vector<int> digits(N);
	for (int i=0; i<N; ++i) {
		cin >> digits[i];
	}
	int num = 0; 
	for (int i=0; i<N; ++i) {
		num *= A;
		num += digits[i];
	}
	vector<int> ans; 
	while (num) {
		ans.push_back(num%B);
		num /= B;
	}
	reverse(ans.begin(), ans.end());
	for (int a : ans) {
		cout << a << ' ';
	} 
	return 0;
}

