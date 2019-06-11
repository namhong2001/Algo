#include <iostream>
#include <iterator>
#include <vector>

using namespace std;


vector<int> numbers;
vector<int> subset;
void print_subset(vector<int>::iterator left, vector<int>::iterator right) {
	if (subset.size() == 6) {
		for (int e : subset) {
			cout << e << ' ';
		}
		cout << '\n';
		return;
	}
	for (auto it=left; it!=right; ++it) {
		subset.push_back(*it);
		print_subset(next(it), right);
		subset.pop_back();
	}
}



int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	while (true) {
		int k;
		cin >> k;
		if (k == 0) break;
		numbers.resize(k);
		for (int i=0; i<k; ++i) {
			cin >> numbers[i];
		}
		print_subset(numbers.begin(), numbers.end());
		cout << '\n';
	}
	return 0;
} 
