#include <iostream>

#define ll long long

using namespace std;

const ll MOD = 1e9+7;

ll inputs[1000001];
ll exp[1000001];
ll exp_psum[1000001];

void gen_input(ll n, ll x1, ll y1, ll c, ll d, ll e1, ll e2, ll f) {
    ll mul = c+d;
    ll add = e1+e2;
    inputs[1] = (x1+y1) % f;

    for (int i=2; i<=n; ++i) {
        inputs[i] = (inputs[i-1]*mul + add) % f;
    }
}

ll pow(ll a, ll n) {
    if (n == 0) return 1;
    if (n == 1) return a;

    ll half = pow(a, n/2);
    ll ret = half * half % MOD;

    if (n%2) {
        ret = ret * a % MOD;
    }
    return ret;
}

void init_exp(int n, int k) {
    exp[1] = k;
    for (int i=2; i<=n; ++i) {
        exp[i] = i*(pow(i, k)-1) % MOD;
        exp[i] = exp[i] * pow(i-1, MOD-2) % MOD;
    }
}

void init_exp_psum(int n, int k) {
    exp_psum[1] = exp[1];
    for (int i=2; i<=n; ++i) {
        exp_psum[i] = (exp_psum[i-1] + exp[i]) % MOD;
    }
}

ll get_power(int n) {
    ll power_sum = 0;
    for (int i=1; i<=n; ++i) {
        ll power = inputs[i]*exp_psum[i] % MOD;
        power = power * (n-i+1) % MOD;
        power_sum += power;
        power_sum %= MOD;
    }
    return power_sum;
}

int main() {
    int T;
    cin >> T;
    for (int t=1; t<=T; ++t) {
        ll n, k, x1, y1, c, d, e1, e2, f;
        cin >> n >> k >> x1 >> y1 >> c >> d >> e1 >> e2 >> f;
        gen_input(n, x1, y1, c, d, e1, e2, f);
        init_exp(n, k);
        init_exp_psum(n, k);
        cout << "Case #" << t << ": " << get_power(n) << endl;
//        for (int i=1; i<=n; ++i) {
//            cout << inputs[i] << ' ';
//        }
    }


    return 0;
}
