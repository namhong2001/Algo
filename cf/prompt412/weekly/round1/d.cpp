#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int main() {
	int N;
	cin >> N;
	if (N <= 3) {
		cout << 1;
		return 0; 
	} 
	vector<int> arr(N);
	for (int i=0; i<N; ++i) cin >> arr[i];
	sort(arr.begin(), arr.end()); 
	if (N <= 10) {
		for (int i=0; i<N; ++i) {
			vector<int> ap = arr;
			ap.erase(ap.begin() + i);
			set<int> diff;
			for (int j=0; j<(int)ap.size()-1; ++j) {
				diff.insert(ap[j+1] - ap[j]);
			}
			if (diff.size() == 1) {
				cout << i+1;
				return 0;
			}
		}
		cout << -1;
		return 0; 
	} else {
		map<int,int> diff;
		for (int i=0; i<N-1; ++i) {
			diff[arr[i+1] - arr[i]]++;
		}
		if (diff.size() > 3) {
			cout << -1;
			return 0;
		} else if (diff.size() == 3) { 
			int mm;
			bool selected = false;
			for (auto de : diff) { 
				if (de.second > 1) {
					if (selected) {
						cout << -1;
						return 0;
					}
					mm = de.first; 
					selected = true;
				}
			}
			for (int i=0; i<N-2; ++i) {
				if (arr[i+1] - arr[i] == mm) continue;
				if (arr[i+2] - arr[i] == mm) {
					cout << i+1+1;
					return 0;
				} else {
					cout << -1;
					return 0;
				} 
			}
		} else if (diff.size() == 2) {
			int mm;
			bool selected = false;
			for (auto de : diff) { 
				if (de.second > 1) {
					if (selected) {
						cout << -1;
						return 0;
					}
					mm = de.first; 
					selected = true;
				}
			}
			if (arr[1] - arr[0] != mm) {
				cout << 1;
				return 0;
			} else if (arr[N-1] - arr[N-2] != mm) {
				cout << N;
				return 0;
			} else {
				cout << -1;
				return 0;
			}
		} else {
			cout << 1;
			return 0;
		}
	} 
	return 0;
}

