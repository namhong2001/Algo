#include <iostream>
#include <vector>

using namespace std;
	
int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	int N;
	cin >> N; 
	vector<int> heap;
	heap.push_back(0);
	for (int i=1; i<=N; ++i) {
		int here = i-1; 
		while (here > 1) {
			int parent = here/2;
			swap(heap[here], heap[parent]);
			here = parent;
		}
		heap[1] = i;
		heap.push_back(1);
	}
	for (int i=1; i<=N; ++i) {
		cout << heap[i] << ' ';
	}
	cout << '\n';
	return 0;
} 
