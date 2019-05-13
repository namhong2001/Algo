#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int> pii;

int main() {
	int n;
	cin >> n;
	vector<pair<int,int>> meeting;
	for (int i=0; i<n; ++i) {
		int a, b;
		cin >> a >> b;
		meeting.push_back({a, b});
	}
	sort(meeting.begin(), meeting.end(), [&](const pii &A, const pii &B){
			if (A.second < B.second) return true;
			else if (A.second == B.second) return A.first < B.first;
			else return false;});
	int last = 0;
	int cnt = 0;
	for (int i=0; i<n; ++i) {
		pair<int,int> &cur = meeting[i];
		if (cur.first < last) continue;
		cnt++;
		last = cur.second;
	}
	cout << cnt << endl;
	return 0;
} 
