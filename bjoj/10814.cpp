#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Person {
    int age;
	int registeredAt;
    string name;
    bool operator < (const Person &rhs) const {
		return age == rhs.age ? registeredAt < rhs.registeredAt : age < rhs.age;
	} 
};

int main() {
    int N;
    cin >> N;
    vector<Person> arr(N);
    for (int i=0; i<N; ++i) {
        cin >> arr[i].age >> arr[i].name;
		arr[i].registeredAt = i; 
    }
	sort(arr.begin(), arr.end());
	for (auto &p : arr) {
		cout << p.age << ' ' << p.name << '\n';
	} 
    return 0;
}

