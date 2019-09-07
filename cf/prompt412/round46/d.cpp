#include <iostream>

using namespace std;

int main() {
	string S;
	cin >> S;
	int N = S.size();
	for (char a : S) {
		if (a == '0' || a == '8') {
			cout << "YES" << '\n' << a;
			return 0; 
		}
	}
	for (int i=0; i<N; ++i) {
		for (int j=i+1; j<N; ++j) {
			string a;
			a.push_back(S[i]);
			a.push_back(S[j]);
			int num = stoi(a);
			if (num % 8 == 0) {
				cout << "YES" << '\n' << a;
				return 0;
			} 
		}
	}
	for (int i=0; i<N; ++i) {
		for (int j=i+1; j<N; ++j) {
			for (int k=j+1; k<N; ++k) {
				string a;
				a.push_back(S[i]);
				a.push_back(S[j]);
				a.push_back(S[k]);
				int num = stoi(a);
				if (num % 8 == 0) {
					cout << "YES" << '\n' << a;
					return 0;
				} 
			}
		} 
	}
	cout << "NO";
	return 0;
}

