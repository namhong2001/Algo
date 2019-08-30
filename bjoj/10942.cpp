#include <iostream>
#include <vector>

using namespace std;

typedef pair<int,int> pii;

vector<int> arr;
vector<int> palindrome(4000, 0); // key = s+e, value = e-s
int N, M; 

void add(int a, int b) { 
	if (a < 1 || b > N) return;
	if (arr[a] == arr[b]) {
		palindrome[a+b] = b-a;
		add(a-1, b+1);
	}
} 

void cal_palindrome(int start) {
	add(start, start);
	add(start, start+1);
}

bool is_palindrome(int s, int e) {
	return palindrome[s+e] >= e-s;
}

int main() { 
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> N;
	arr.resize(N+1);
	for (int i=1; i<=N; ++i) {
		cin >> arr[i];
	}
	for (int i=1; i<=N; ++i) {
		cal_palindrome(i);
	}
	int M;
	cin >> M;
	for (int i=0; i<M; ++i) {
		int s, e;
		cin >> s >> e; 
		cout << (is_palindrome(s, e) ? 1 : 0) << '\n';
	} 
    return 0;
}

