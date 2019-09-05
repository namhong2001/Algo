#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> ans;
	for (int i=1; i<=N; ++i) {
		int before;
		cin >> before;
		ans.insert(ans.end() - before, i);
	}
	for (int a : ans) {
		cout << a << ' ';
	} 
    return 0;
}

