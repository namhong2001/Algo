#include <iostream>
#include <functional>
#include <vector>

using namespace std;

typedef function<int(int,int)> Merge;

int N;
vector<int> min_d;
vector<int> max_d; 


int init(vector<int> &target, vector<int> &in, int node, int s, int e, Merge merge) { 
	if (s == e) return target[node] = in[s];
	int mid = (s+e)/2;
	return target[node] = merge(init(target, in, 2*node, s, mid, merge), init(target, in, 2*node+1, mid+1, e, merge));
}

int query(vector<int> &target, int l, int r, int node, int nl, int nr, Merge merge) {
	if (l<=nl && nr<=r) return target[node];
	int mid = (nl + nr)/2;
	if (mid < l) return query(target, l, r, 2*node+1, mid+1, nr, merge);
	else if (mid+1 > r) return query(target, l, r, 2*node, nl, mid, merge);
	else return merge(query(target, l, r, 2*node, nl, mid, merge), query(target, l, r, 2*node+1, mid+1, nr, merge));
} 

int main() {
	cin >> N;
	vector<int> arr(N);
	min_d.resize(4*N);
	max_d.resize(4*N);
	const auto my_min = [](int A, int B){return min(A, B);};
	const auto my_max = [](int A, int B){return max(A, B);};
	for (int i=0; i<N; ++i) cin >> arr[i];
	init(min_d, arr, 1, 0, N-1, my_min);
	init(max_d, arr, 1, 0, N-1, my_max);
	int Q;
	cin >> Q;
	for (int i=0; i<Q; ++i) {
		int l, r;
		cin >> l >> r;
		l--, r--;
		int max_val = query(max_d, l, r, 1, 0, N-1, my_max);
		int min_val = query(min_d, l, r, 1, 0, N-1, my_min);
		cout << max_val - min_val << '\n';
	} 
    return 0;
}

