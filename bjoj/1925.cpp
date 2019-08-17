#include <iostream>

using namespace std;

struct V {
	int x, y;
};

int dist(V a, V b) {
	return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

int ccw(V a, V b, V c) {
	int ret = a.x*b.y + b.x*c.y + c.x*a.y - b.x*a.y - c.x*b.y - a.x*c.y;
	if (ret == 0) return ret;
	return ret / abs(ret);
} 

bool isJung(V a, V b, V c) {
	return dist(a, b) == dist(b, c) && dist(b, c) == dist(c, a);
}

bool isTwo(V a, V b, V c) {
	return dist(a, b) == dist(b, c) || dist(b, c) == dist(c, a) || dist(c, a) == dist(a, b);
} 

int dot(V a, V b, V c) {
	int ret = (a.x-b.x)*(c.x-b.x) + (a.y-b.y)*(c.y-b.y);
	if (ret == 0) return ret;
	return ret / abs(ret);
} 

int angle(V a, V b, V c) {
	return dot(a, b, c) * dot(b, c, a) * dot(c, a, b);
}

int main() {
	V a, b, c;
	cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
	if (ccw(a, b, c) == 0) {
		cout << "X" << endl;
	} else if (isJung(a, b, c)) cout << "JungTriangle" << endl;
	else if (isTwo(a, b, c)) {
		if (angle(a, b, c) == -1) {
			cout << "Dunkak2Triangle" << endl;
		} else if (angle(a, b, c) == 0) {
			cout << "Jikkak2Triangle" << endl;
		} else {
			cout << "Yeahkak2Triangle" << endl;
		}
	} else {
		if (angle(a, b, c) == -1) {
			cout << "DunkakTriangle" << endl;
		} else if (angle(a, b, c) == 0) {
			cout << "JikkakTriangle" << endl;
		} else {
			cout << "YeahkakTriangle" << endl;
		}
	} 
	return 0;
}

