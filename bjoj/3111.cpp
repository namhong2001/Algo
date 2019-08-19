#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() { 
	string A, S;
	cin >> A >> S;
	vector<int> F;
	vector<int> B;
	for (int i=0; i<(int)S.size()-(int)A.size()+1; ++i) {
		bool ok = true;
		for (int j=0; j<(int)A.size(); ++j) {
			if (S[i+j] != A[j]) {
				ok = false;
				break;
			}
		}
		if (ok) {
			F.push_back(i);
		} 
	}
	B = F;
	reverse(B.begin(), B.end());
	int left = 0, right = (int)S.size()-1;
	int findex = 0, bindex = 0; 
	vector<char> L;
	vector<char> R; 
	bool order = false; 
	while (left <= right) {
		if (!order) {
			while (findex <= (int)F.size()

		
		
		
	
	
			

		

		
		
	



	return 0;
}

