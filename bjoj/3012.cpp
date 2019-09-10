#include <iostream>
#include <map>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

const ll MOD = 1e5;

int N;
string S;

ll d[201][201][2];  // d[start][end][inside_only]
bool over_limit[201][201][2];

map<char,char> match {{'{', '}'}, {'(', ')'}, {'[', ']'}};
map<char,char> rmatch {{'}', '{'}, {')', '('}, {']', '['}}; 

bool is_left(char c) {
	return c == '{' || c == '[' || c == '(';
}
bool is_right(char c) {
	return c == '}' || c == ']' || c == ')';
}

ll solve(int start, int end, bool inside_only) {
	if (end < start) return 1;
	ll &ret = d[start][end][(int)inside_only];
	if (ret != -1) return ret;
	ret = 0; 
	bool &my_over = over_limit[start][end][(int)inside_only];
	if (S[start] == '?' && S[end] == '?') {
		ret += 3*solve(start+1, end-1, false); 
		my_over = my_over || over_limit[start+1][end-1][0]; 
	} else if ((S[start] == '?' && is_right(S[end])) || (S[end] == '?' && is_left(S[start]))) {
		ret += solve(start+1, end-1, false);
		my_over = my_over || over_limit[start+1][end-1][0]; 
	} else if (match[S[start]] == S[end]) {
		ret += solve(start+1, end-1, false);
		my_over = my_over || over_limit[start+1][end-1][0]; 
	}
	if (ret > MOD) {
		my_over = true;
		ret %= MOD;
	}
	if (inside_only) return ret; 
	for (int i=start+1; i<=end-2; i+=2) {
		ll cases = solve(start, i, false) * solve(i+1, end, true);
		if (cases > 0) {
			ret += cases;
			my_over = my_over || over_limit[start][i][0] || over_limit[i+1][end][1];
		}
	}
	if (ret > MOD) {
		my_over = true;
		ret %= MOD;
	}
	return ret;
} 

string zero_padding(int num, int len) { 
	string ret = to_string(num);
	reverse(ret.begin(), ret.end());
	while ((int)ret.size() < len) {
		ret.push_back('0');
	}
	reverse(ret.begin(), ret.end());
	return ret;
}
	
int main() {
	memset(d, -1, sizeof(d));
	cin >> N >> S;
	if (N%2) {
		cout << 0;
		return 0;
	} 
	ll ans = solve(0, N-1, false);
	if (over_limit[0][N-1][0]) {
		cout << zero_padding(ans, 5);
	} else {
		cout << ans; 
	}
	return 0;
}

