#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr;
    int sum = 0;
    int biggest = -987654321;
    while(n--) {
        int a;
        cin >> a;
        if (a > biggest) biggest = a;
        if (a == 0) continue;
        if ((sum <= 0 && a < 0) || (sum >=0 && a > 0)) {
            sum += a;
        } else {
            arr.push_back(sum);
            sum = a;
        }
    }

    if (sum != 0) arr.push_back(sum);

    if (arr.empty()) {
        cout << 0;
        return 0;
    } else if (arr.size() == 1 && arr[0] < 0) {
        cout << biggest;
        return 0;
    }
    int start = arr[0] > 0 ? 0 : 1;
    int end = start+2;
    int candi = arr[start];
    int max = candi;
    while(end + 2 < arr.size()) {
        if (arr[end+1]*-1 > arr[end]) {
            if (candi > max) {
                max = candi;
            }
            start = end+2;
            candi = arr[end+2];
        } else {
        }
        int next = arr[end-1] + arr[end];
        if (next > 0) {
            candi +=  next;
        } else {
            if (candi > max) {
                max = candi;
            }
            start = end;
            candi = arr[end];
        }
        end += 2;
    }
    if (candi > max) {
        max = candi;
    }
    cout << max;

    return 0;
}
