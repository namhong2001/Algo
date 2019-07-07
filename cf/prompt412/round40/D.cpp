#include <iostream>
#include <cstring>

using namespace std; 

int main() {
	int N;
	string S, T; 
	cin >> N >> S >> T;
	int match[26][26];
	memset(match, -1, sizeof(match));
	int dist = 0; 
	for (int i=0; i<N; ++i) {
		if (S[i] != T[i]) {
			dist++;
			match[S[i]-'a'][T[i]-'a'] = i+1;
		}
	} 
	for (int i=0; i<26; ++i) {
		for (int j=0; j<26; ++j) {
			if (match[i][j] != -1 && match[j][i] != -1) { 
				cout << dist-2 << endl << match[i][j] << ' ' << match[j][i] << endl;
				return 0;
			} 
		}
	}
	for (int i=0; i<26; ++i) {
		for (int j=0; j<26; ++j) {
			if (match[i][j] != -1) { 
				for (int k=0; k<26; ++k) {
					if (match[j][k] != -1) { 
						cout << dist-1 << endl << match[i][j] << ' ' << match[j][k] << endl; 
						return 0;
					}
				}
			} 
		}
	}
	cout << dist << endl << -1 << ' ' << -1 << endl; 
	return 0;
}

