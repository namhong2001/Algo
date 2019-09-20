#include <iostream>
#include <cstring>

using namespace std;

int main() {
	int N, D;
	string S;
	cin >> N >> D >> S;
	int jump[N];
	memset(jump, -1, sizeof(jump));
	jump[0] = 0;
	for (int i=0; i<N; ++i) {
		if (jump[i] != -1) {
			for (int j=1; j<=D && i+j<N; ++j) {
				if (S[i+j] == '1' && jump[i+j] == -1) jump[i+j] = jump[i]+1;
			}
		}
	}
	cout << jump[N-1]; 
    return 0;
}

