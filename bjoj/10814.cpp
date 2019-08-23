#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Person {
    int age;
    string name;
    bool operator < (const Person &rhs) const {
        
        
}

int main() {
    int N;
    cin >> N;
    vector<Person> arr;
    for (int i=0; i<N; ++i) {
        cin >> arr[i].age >> arr[i].name;
    }
    






    return 0;
}

