#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct jew{
	int m, v;
} J[300010];
int n, k, C[300010], bck=1;
ll ans;
priority_queue<int> Q;
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin>>n>>k;
    for(int i=1; i<=n; i++) cin>>J[i].m>>J[i].v;
    for(int i=1; i<=k; i++) cin>>C[i];
    sort(C+1, C+k+1);
    sort(J+1, J+n+1, [](jew a, jew b){ return a.m<b.m; });
    for(int i=1; i<=k; i++){
    	while(bck<=n && J[bck].m<=C[i]) Q.push(J[bck].v), bck++;
    	if(!Q.empty()) ans+=Q.top(), Q.pop();
	}
	cout<<ans;
    return 0;
}
