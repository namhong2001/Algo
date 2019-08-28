#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

typedef pair<int,int> pii;

vector<int> arr;
unordered_set<pii> palindrome;
int N, M; 

void add(int a, int b) {
	if (a < 0 || b >= N) return;
	if (arr[a] == arr[b]) {
		palindrome.emplace(a, b);
		add(a-1, b+1);
	}
} 

void add_palindrome(int start) {
	add(start, start);
	add(start, start+1);
}

int main() { 
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> N;
	arr.resize(N);
	for (int i=0; i<N; ++i) {
		cin >> arr[i];
	}
	for (int i=0; i<N; ++i) {
		add_palindrome(i);
	}
	int M;
	cin >> M;
	for (int i=0; i<M; ++i) {
		int s, e;
		cin >> s >> e;
		s--, e--;
		cout << (palindrome.find({s, e}) == palindrome.end() ? 0 : 1) << '\n';
	} 
    return 0;
}

