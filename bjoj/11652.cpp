#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<ll,int> pli;

bool comp(const pli &A, const pli &B) {
	return A.second == B.second ? A.first < B.first : A.second > B.second;
}

int main() { 
	int N;
	cin >> N;
	map<ll, int> cnt;
	for (int i=0; i<N; ++i) {
		ll num;
		cin >> num;
		cnt[num]++;
	}
	cout << min_element(cnt.begin(), cnt.end(), comp)->first;
	return 0;
}

