#include <iostream>

using namespace std;

int occur(string &C, string &S) {
	string T = C+S; 
	int ts = T.size();
	int cs = C.size();
	int L = 0, R = 0;
	int Z[200010] = {};
	for (int i=1; i<ts; ++i) {
		if (i>R) {
			L = R = i;
			while (R < ts && T[R-L] == T[R]) R++;
			Z[i] = R-L; 
			R--;
		} else {
			if (Z[i-L] < R-i+1) Z[i] = Z[i-L];
			else { 
				L = i;
				while (R < ts && T[R-L] == T[R]) R++;
				Z[i] = R-L; 
				R--;
			} 
		}
	}
	int ret = 0;
	for (int i=cs; i<ts; ++i) {
		if (Z[i] >= cs) ret++;
	}
	return ret; 
} 

int main() {
	string C, S;
	cin >> C >> S;
	cout << occur(C, S); 
	return 0;
}

