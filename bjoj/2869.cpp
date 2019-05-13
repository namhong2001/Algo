#include <iostream>

using namespace std;

int main() {
	int a, b, v;
	cin >> a >> b >> v;
	int to = v-a;
	int perday = a-b;
	int ans = to/perday;	
	if (to%perday > 0) ans++;
	ans++;
	cout << ans << endl;
	return 0;
}
