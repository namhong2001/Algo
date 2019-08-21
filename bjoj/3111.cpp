#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 987654321;

int main() { 
	string A, S;
	cin >> A >> S; 
	int alen = A.size();
	int slen = S.size();
	vector<int> match;
	for (int i=0; i<(int)S.size()-(int)A.size()+1; ++i) {
		bool ok = true;
		for (int j=0; j<(int)A.size(); ++j) {
			if (S[i+j] != A[j]) {
				ok = false;
				break;
			}
		}
		if (ok) {
			match.push_back(i);
		} 
	}
	if (match.empty()) {
		cout << S;
		return 0;
	}
	vector<int> L;
	int p = 0;
	for (auto m : match) {
		if (m >= p) {
			L.push_back(m);
			p = m + alen;
		} 
	}
	vector<int> R; 
	reverse(match.begin(), match.end()); 
	p = slen-1;
	for (auto m : match) {
		if (m+alen-1 <= p) {
			R.push_back(m);
			p = m-1;
		} 
	} 
	vector<int> erase;
	int lindex = 0, rindex = 0;
	int lpos = 0, rpos = slen-1;
	while (true) {
		if (L[lindex] + alen <= rpos+1) {
			erase.push_back(L[lindex]);
			lpos = L[lindex]+alen;
			lindex++;
		} else break;

		if (R[rindex] >= lpos) {
			erase.push_back(R[rindex]);
			rpos = R[rindex]-1;
			rindex++;
		} else break;
	} 
	sort(erase.begin(), erase.end());
	int eindex = 0;
	for (int i=0; i<slen; ++i) {
		if (eindex < (int)erase.size() && i == erase[eindex]) { 
			i += alen; 
			i--;
			eindex++;
			continue;
		} 
		cout << S[i];
	}
	return 0;
}

