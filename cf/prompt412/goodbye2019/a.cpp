#include <iostream>

using namespace std;

int n, x;
int arr[100005];
int ans = (int)1e9 + 5;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

    cout << 1 << " " << 1 << '\n';

    for(int i = 0; i < 10; i++) {
        cout << '.';
    }
    cout << '\n';

    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 10; j++) {
            cout << '#';
        }
        cout << '\n';
    }

  return 0;
}