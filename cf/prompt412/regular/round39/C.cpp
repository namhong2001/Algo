#include <iostream>
#include <list>
#include <iterator>
#include <vector>
#include <cassert>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
	if (a < b) return gcd(b, a);
	return a % b == 0 ? b : gcd(b, a%b);
}

ll lcm(ll a, ll b) {
	ll g = gcd(a, b);
	return g*(a/g)*(b/g);
}

vector<ll> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643};


bool check(list<ll> &arr) {
	for (auto it = arr.begin(); it != arr.end(); ++it) {
		if (next(it) == arr.end()) break;
		if (gcd(*it, *next(it)) != 1) return false; 
	}
	return true;
} 

int main() {
	int N;
	cin >> N;
	list<ll> arr;
	for (int i=0; i<N; ++i) { 
		ll a;
		cin >> a; 
		arr.push_back(a);
	}
	ll pre = arr.front(); 
	int cnt = 0;
	for (auto it = next(arr.begin()); it != arr.end(); ++it) {
		if (gcd(pre, *it) == 1) continue;
		ll l = lcm(pre, *it);
		for (ll p : primes) {
			if (gcd(l, p) == 1) {
				it = arr.insert(it, p);
				cnt++;
				it++; 
				break;
			}
		}
		pre = *it;
	}

	//assert(check);

	cout << cnt << endl;
	for (auto a : arr) {
		cout << a << ' ';
	}
	return 0;
} 
