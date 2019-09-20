#include <iostream>
#include <set>

using namespace std;

typedef pair<int,int> pii;

int main() {
	int n, m;
	cin >> n >> m;
	int arr[n][m];
	
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			cin >> arr[i][j];
		}
	}

	bool isOk = true;

	for (int i=0; i<n; ++i) {
		vector<int> failpos;
		set<pii> myset;
		for (int j=0; j<m; ++j) {
			if (arr[i][j] != j+1) failpos.push_back(j);
			myset.insert(min(j+1, arr[i][j]), max(j+1, arr[i][j]));
		}
		
		if (failpos.size() > 4) {
			isOk = false;
			break;
		} else if (failpos.size() == 4) {
			if (myset.size() != 2) {
				isOk = false;
				break;
			}
		}


		
		

