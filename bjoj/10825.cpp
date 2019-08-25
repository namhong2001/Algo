#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student {
	int korean;
	int english;
	int math;
	string name;
	bool operator < (const Student& rhs) const {
		return korean != rhs.korean ? korean > rhs.korean :
			english != rhs.english ? english < rhs.english :
			math != rhs.math ? math > rhs.math :
			name < rhs.name;
	}
};


int main() {
	int N;
	cin >> N;
	vector<Student> arr(N);
	for (int i=0; i<N; ++i) {
		cin >> arr[i].name >> arr[i].korean >> arr[i].english >> arr[i].math;
	}
	sort(arr.begin(), arr.end());
	for (auto &s : arr) {
		cout << s.name << '\n';
	}
	return 0;
}

