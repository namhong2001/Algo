#include <iostream>
#include <functional>
#include <vector>

using namespace std;

typedef function<int(int,int)> Merge;

const int NUM_MAX = 1e6;

int N;
vector<int> min_d;
vector<int> max_d; 
vector<int> sum_d;

const auto my_min = [](int A, int B){return min(A, B);};
const auto my_max = [](int A, int B){return max(A, B);}; 
const auto sum = [](int A, int B){return A+B;};

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

int update(vector<int> &target, int index, int val, int node, int nl, int nr, Merge merge) {
	if (index > nr || index < nl) return target[node];
	if (nl == nr) return target[node] = val;
	int mid = (nl + nr)/2;
	return target[node] = merge(update(target, index, val, 2*node, nl, mid, merge), update(target, index, val 2*node+1, mid+1, nr, merge));
}

int main() {
	cin >> N;
	vector<int> score(N);
	vector<int> cnt(NUM_LIMIT+1); 
	sum_d.resize(4*(NUM_LIMIT+1));
	for (int i=0; i<N; ++i) {
		cin >> score[i];
		cnt[score[i]]++;
	}
	init(sum_d, cnt, 1, 0, N-1, sum);
	int Q;
	cin >> Q;
	for (int i=0; i<Q; ++i) {
		int action;
		cin >> action;
		if (action == 1) {
			int index, val;
			cin >> index >> val; 
			index--;
			int num = score[index];
			cnt[num]--;
			update(sum_d, num, cnt[num], 1, 0, NUM_LIMIT, sum);
			score[index] = val;
			cnt[val]++;
			update(sum_d, num, cnt[val], 1, 0, NUM_LIMIT, sum);
		} else {
			int index;
			cin >> index;
			index--;
			int num = score[index];
			int ans = query(sum_d, num+1, NUM_LIMIT, 1, 0, NUM_LIMIT, sum);
			cout << ans + 1 << '\n'; 
		} 
	} 
    return 0;
}

