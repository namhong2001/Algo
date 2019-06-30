#include <iostream>

using namespace std;

bool is_operator(char c) {
	return c == '|' || c == '&' || c == '^';
} 

char opponent(char c) {
	if (c == 'X') return 'x';
	else if (c == 'x') return 'X';
	else if (c == '1') return '0';
	else if (c == '0') return '1';
	return '1'; // error
}

string expr;
char eval(int left, int right, bool revealed) {
	if (expr[left] == '(' && expr[right] == ')' && !revealed) return eval(left+1, right-1, true);
	if (left == right) return expr[left];
	int operator_index = 0; 
	int bracket_cnt = 0;
	for (int i=left; i<=right; ++i) {
		if (expr[i] == '(') bracket_cnt++;
		else if (expr[i] == ')') bracket_cnt--; 
		else if (is_operator(expr[i]) && bracket_cnt == 0) {
			operator_index = i;
			break;
		}
	}
	char l = eval(left, operator_index-1, false);
	char r = eval(operator_index+1, right, false);
	char op = expr[operator_index];
	if (op == '|') {
		if (l == r) return l;
		else if (l == '1' || r == '1') return '1';
		else if (l == '0') return r;
		else if (r == '0') return l;
		else return '1';
	} else if (op == '&') {
		if (l == r) return l;
		else if (l == '0' || r == '0') return '0';
		else if (l == '1') return r;
		else if (r == '1') return l;
		else return '0';
	} else if (op == '^') {
		if (l == '1') return opponent(r);
		else if (r == '1') return opponent(l);
		else if (l == '0') return r;
		else if (r == '0') return l;
		else if (l != r) return '1';
		else return '0';
	}
	return '1'; // error
} 

int main() {
	int T;
	cin >> T;
	for (int t=1; t<=T; ++t) { 
		cin >> expr;
		char result = eval(0, expr.size()-1, false); 
		int ans = 0;
		if (result == 'X' || result == 'x') {
			ans = 1;
		}
		cout << "Case #" << t << ": " << ans << '\n'; 
	}
	return 0;
} 
