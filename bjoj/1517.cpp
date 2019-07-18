#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int,int> pii; 
typedef long long ll;

struct Segment {
	vector<int> d;
	int N;
	Segment(vector<int> &arr) { 
		init(arr);
	}
	void init(vector<int> &arr) {
		N = arr.size(); 
		d.resize(2*N);
		copy(arr.begin(), arr.end(), d.begin()+N);
		for (int i=N-1; i>0; --i) {
			d[i] = d[2*i] + d[2*i+1];
		}
	}
	void update(int index, int value) {
		index += N;
		d[index] = value; 
		index /= 2;
		while (index > 0) {
			d[index] = d[index*2] + d[index*2+1];
			index /= 2;
		}
	}
	int query(int s, int e) {
		int ret = 0;
		s += N;
		e += N;
		while (s < e) {
			if (s%2) ret += d[s++];
			if (e%2) ret += d[--e];
			s /= 2, e /= 2;
		}
		return ret;
	} 
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N;
	cin >> N;
	priority_queue<pii> pq;
	for (int i=0; i<N; ++i) {
		int a;
		cin >> a;
		pq.emplace(a, i);
	}
	vector<int> arr(N, 1);
	Segment seg(arr);
	ll ans = 0;
	while (!pq.empty()) {
		pii here = pq.top();
		pq.pop();
		int my_index = seg.query(0, here.second+1);
		ans += (int)pq.size() + 1 - my_index; 
		seg.update(here.second, 0);
	}
	cout << ans << endl;
	return 0;
} 
