#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

int main() {
    int n, k;
    while(scanf("%d%d", &n, &k)!=EOF) {
        map<long long, long long> primes;
        for(int i=2; i*i<=k; ++i) {
            while(k%i==0) {
                primes[i]++;
                k/=i;
            }
        }
        if(k>1)
            primes[k]++;
        long long ret=1;
        for(auto &prime:primes) {
            long long sum=0;
            if(prime.first>n)
                break;
            for(int p=prime.first; p<=n; p*=prime.first) {
                sum+=n/p;
            }
            for(int i=0; i<min(sum, prime.second); ++i) {
                ret*=prime.first;
            }
        }
        cout<<ret<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
