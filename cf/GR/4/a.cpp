#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;
	int total = 0;
	vector<int> parties(N);
	for (int i=0; i<N; ++i) {
		cin >> parties[i];
		total += parties[i];
	}
	int alice = parties[0];
	vector<int> coal;
	coal.push_back(0); 
	int coal_cnt = alice;
	for (int i=1; i<N; ++i) {
		if (alice >= parties[i]*2) {
			coal.push_back(i);
			coal_cnt += parties[i];
		}
	}
	if (coal_cnt*2 > total) {
		cout << coal.size() << endl;
		for (int index : coal) {
			cout << index+1 << ' ';
		}
		cout << endl;
	} else {
		cout << 0 << endl;
	} 
	return 0;
}
