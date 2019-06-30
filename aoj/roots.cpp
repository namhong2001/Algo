#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

const double NA = -100.0;


vector<double> derivative(vector<double> &exp) {
	int n = exp.size()-1;
	vector<double> ret;
	for (double e : exp) {
		ret.push_back(e*n--);
	}
	ret.pop_back();
	return ret;
}

// <=0: true >0: false

double f(double x, vector<double> &exp) {
	int n = exp.size()-1;
	double y = 0;
	for (double e : exp) {
		y += e * pow(x, (double)n--);
	}
	return y;
}
	


bool decision(vector<double> &exp, double x) { 
	return f(x, exp)<=0.0;
} 

double bisection(vector<double> &exp, double left, double right) { 
	if (f(left, exp) == 0.0) return left;
	else if (f(right, exp) == 0.0) return right;
	else if (f(left, exp) > 0 && f(right, exp) > 0) return NA;
	else if (f(left, exp) <=0 && f(right, exp) <= 0) return NA; 

	if (f(left, exp) > 0) swap(left, right); 

	for (int i=0; i<100; ++i) {
		double mid = (left+right)/2;
		if (decision(exp, mid)) {
			left = mid;
		} else {
			right = mid;
		}
	}
	return left;
} 

vector<double> solve(vector<double> &exp) {
	if (exp.size() == 2) {
		return { -exp[1]/exp[0] };
	}
	vector<double> der = derivative(exp);
	vector<double> mm = solve(der);
	mm.insert(mm.begin(), -10.0);
	mm.push_back(10.0); 

	vector<double> ret;
	for (int i=1; i<(int)mm.size(); ++i) {
		double cand = bisection(exp, mm[i-1], mm[i]);
		if (cand != NA) ret.push_back(cand);
	}
	return ret; 
}
	
int main() {
	int C;
	cin >> C;
	while (C--) {
		int N;
		cin >> N;
		vector<double> exp(N+1);
		for (int i=0; i<N+1; ++i) {
			cin >> exp[i];
		}
		vector<double> ans = solve(exp);
		for (double a : ans) {
			cout << fixed << setprecision(10) << a << ' ';
		}
		cout << endl;
	}
	return 0;
} 
