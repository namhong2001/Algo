#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

struct V {
	double x, y;
};

double area(vector<V> polygon) { 
	double ret = 0;
	int N = polygon.size();
	for (int i=0; i<N; ++i) {
		int j = (i+1)%N;
		ret += polygon[i].x*polygon[j].y - polygon[i].y*polygon[j].x;
	}
	return fabs(ret) / 2.0;
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr); 
	int N;
	cin >> N; 
	vector<V> polygon(N);
	for (int i=0; i<N; ++i) {
		cin >> polygon[i].x >> polygon[i].y;
	} 
	cout << fixed << setprecision(1) << area(polygon) << '\n';
	return 0;
}

