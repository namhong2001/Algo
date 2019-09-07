#include <iostream>
#include <map>

using namespace std;

map<char,int> cost {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

int romeToNum(string S) {
	int N = S.size();
	int ret = 0;
	for (int i=0; i<N; ++i) {
		if (i<N-1 && cost[S[i]] < cost[S[i+1]]) {
			int c = cost[S[i+1]] - cost[S[i]];
			ret += c; 
			i++;
		} else {
			ret += cost[S[i]];
		}
	}
	return ret; 
} 

string numToRome(int num) {
	string ret;
	while (num >= 1000) {
		ret += 'M';
		num -= 1000;
	}
	if (num >= 900  && num - 900 < 100) {
		ret += "CM";
		num -= 900;
	}
	if (num >= 500) {
		ret += "D";
		num -= 500;
	}
	if (num >= 400 && num - 400 < 100) {
		ret += "CD";
		num -= 400;
	}
	while (num >= 100) {
		ret += 'C';
		num -= 100;
	}

	if (num >= 90  && num - 90 < 10) {
		ret += "XC";
		num -= 90;
	}
	if (num >= 50) {
		ret += "L";
		num -= 50;
	}
	if (num >= 40 && num - 40 < 10) {
		ret += "XL";
		num -= 40;
	}
	while (num >= 10) {
		ret += 'X';
		num -= 10;
	}
	
	if (num >= 9  && num - 9 < 1) {
		ret += "IX";
		num -= 9;
	}
	if (num >= 5) {
		ret += "V";
		num -= 5;
	}
	if (num >= 4 && num - 4 < 1) {
		ret += "IV";
		num -= 4;
	}
	while (num >= 1) {
		ret += 'I';
		num -= 1;
	}
	return ret; 
}

int main() {
	string a, b;
	cin >> a >> b;
	int anum = romeToNum(a);
	int bnum = romeToNum(b);
	int num = anum + bnum;
	string str = numToRome(num);
	cout << num << '\n' << str; 
	return 0;
}

