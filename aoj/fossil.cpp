#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct Point {
	double x, y;
};

bool between(Point &A, Point &B, double x) {
	return (A.x <= x && x <= B.x) || (B.x <= x && x <= A.x);
}

double f(Point &A, Point &B, double x) {
	double dx = x - A.x;
	return (B.y - A.y)/(B.x - A.x)*dx + A.y;
} 

int N, M;
double diff(vector<pair<Point,Point>> &upper, vector<pair<Point,Point>> &lower, double x) {
	double up = 101;
	for (auto &u : upper) {
		if (between(u.first, u.second, x)) {
			up = min(up, f(u.first, u.second, x));
		}
	}
	double lo = -1;
	for (auto &l : lower) {
		if (between(l.first, l.second, x)) {
			lo = max(lo, f(l.first, l.second, x));
		}
	}
	return up - lo;
} 

int main() {
	int C;
	cin >> C;
	while (C--) {
		cin >> N >> M;
		vector<Point> A(N+1);
		vector<Point> B(M+1);
		double A_left = 101;
		double B_left = 101;
		double A_right = -1;
		double B_right = -1;
		for (int i=0; i<N; ++i) {
			cin >> A[i].x >> A[i].y;
			A_left = min(A_left, A[i].x);
			A_right = max(A_right, A[i].x);
		}
		A[N] = A[0];
		for (int i=0; i<M; ++i) {
			cin >> B[i].x >> B[i].y;
			B_left = min(B_left, B[i].x);
			B_right = max(B_right, B[i].x);
		}
		B[M] = B[0];
		vector<pair<Point,Point>> upper;
		vector<pair<Point,Point>> lower;
		for (int i=1; i<N+1; ++i) {
			if (A[i].x < A[i-1].x) {
				upper.push_back({A[i-1], A[i]});
			} else if (A[i].x > A[i-1].x) {
				lower.push_back({A[i-1], A[i]});
			}
		}
		for (int i=1; i<M+1; ++i) {
			if (B[i].x < B[i-1].x) {
				upper.push_back({B[i-1], B[i]});
			} else if (B[i].x > B[i-1].x) {
				lower.push_back({B[i-1], B[i]});
			}
		}
		double left = max(A_left, B_left);
		double right = min(A_right, B_right);
		if (left >= right) {
			cout << 0 << '\n';
			continue;
		} 
		double l = left, r = right;
		for (int i=0; i<100; ++i) {
			double a = (2*l+r)/3;
			double b = (l+2*r)/3;
			if (diff(upper, lower, a) < diff(upper, lower, b)) {
				l = a;
			} else {
				r = b;
			}
		}
		double ans = max(0.0, diff(upper, lower, l));
		cout << fixed << setprecision(10) << ans << '\n';
	} 
	return 0;
} 
