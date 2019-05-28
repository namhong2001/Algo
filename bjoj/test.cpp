#include <vector>
#include <iostream>
#include <cstring>
#include <queue>

using namespace std ;

int N, M, K;
int cache[100][1<<14];
vector<int> JEWELS;
vector<vector<pair<int, int>>> adj;

int solve(int here, int jewel){
    int &ret=cache[here][jewel];
    if(ret!=-1)
        return ret;
    ret=0;
    int nJewel=__builtin_popcount(jewel);
    int isJewel=JEWELS[here];

    for(auto p:adj[here]){
        int there=p.first, cost=p.second;
        if(nJewel>cost)
            continue;
        ret=max(ret, solve(there, jewel));
        if(isJewel!=-1 && !(jewel & (1<<isJewel)) && nJewel+1<=cost){
            ret=max(ret, solve(there, (jewel | (1<<isJewel)))+1);
        }
    }
    return ret;
}
int main(){
    cin>>N>>M>>K;
    adj.resize(N);
    JEWELS=vector<int>(N, -1);
    memset(cache, -1, sizeof(cache));
    int cnt=0;
    for(int i=0; i<K; ++i){
        int index;
        cin>>index; index--;
        JEWELS[index]=cnt++;
    }

    for(int i=0; i<M; ++i){
        int a, b, c;
        cin>>a>>b>>c;
        a--; b--;
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }

    solve(0, 0); 
	int ans = 0;
	for (int i=0; i<1<<14; ++i) {
		if (cache[0][i] != -1) {
			ans = max(ans, __builtin_popcount(i)); 
		}
	} 
	if (JEWELS[0] != -1) ans++;
	cout << ans << endl; 
    return 0;
}
