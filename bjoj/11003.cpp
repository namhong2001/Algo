#include <iostream>
#include <deque>

using namespace std;

const int N_MAX = 5000000;

int arr[N_MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    deque<int> window;
    int n, l;
    cin >> n >> l;

    for (int i=0; i<n; ++i) {
        cin >> arr[i];
        while (!window.empty() && window.front() <= i-l) {
            window.pop_front();
        }
        while (!window.empty() && arr[window.back()] > arr[i]) {
            window.pop_back();
        }
        window.push_back(i);
        cout << arr[window.front()] << ' ';
    }

    return 0;
}
