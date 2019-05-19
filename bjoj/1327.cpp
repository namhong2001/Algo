#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int get_bit(int num, int index) {
	num <<= index*3;
	return num;
}

int get_num(int status, int index) {
	return (status & 7<<index*3) >> index*3;
} 

int rev(int here, int index, int cnt) {
	int rep = 0;
	for (int i=0; i<cnt; ++i) {
		int target_num = get_num(here, index+i); 
		rep |= target_num << (index+cnt-i-1)*3;
	}
	int mask = ((8<<(cnt-1)*3)-1) << 3*index; 
	return (here ^ (here & mask)) | rep;
} 


void print(int status, int n) {
	for (int i=0; i<n; ++i) {
		cerr << get_num(status, i) << ' ';
	}
	cerr << endl;
}
	

int main() {
	int n, k;
	cin >> n >> k;
	int start = 0;
	for (int i=0; i<n; ++i) {
		int a; 
		cin >> a;
		a--;
		start |= get_bit(a, i);
	}
	int goal = 0;
	for (int i=0; i<n; ++i) {
		goal |= get_bit(i, i);
	} 

	vector<int> d(1<<3*n, -1); 
	d[start] = 0;
	queue<int> q;
	q.push(start); 
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		if (here == goal) break;
		for (int i=0; i<=n-k; ++i) {
			int next = rev(here, i, k);
			//cerr << "rev " << i << endl;
			//print(here, n);
			//print(next, n);
			if (d[next] == -1) {
				q.push(next);
				d[next] = d[here]+1;
			}
		}
	}
	cout << d[goal] << endl;
	return 0;
} 
