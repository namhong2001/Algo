#include<bits/stdc++.h>
using namespace std;
#define mx 100005
int table[mx][17];
int arr[mx];
vector<int> mp[mx];
int end1[mx];
void build(int n)
{
    memset(table, -1, sizeof table);
    for(int i=1; i<=n; i++)
        table[i][0] = arr[i];
    for(int j=1; (1<<j)<=n; j++){
        for(int i=1; i+(1<<j)-1 <=n; i++){
            table[i][j] = min(table[i][j-1], table[i + (1<<(j-1))][j-1]);
        }
    }
    memset(end1, 0, sizeof end1);
    arr[n+1] = 0;
    for(int i=n; i>=1; i--){
        if(arr[i+1]==1 && arr[i]==1){
            end1[i] = end1[i+1];
        }
        else if(arr[i]==1){
            end1[i] = i;
        }
    }
}
int query(int l, int r)
{
    int len = r-l+1;
    int k = log2(len);
    return min(table[l][k], table[r - (1<<k) + 1][k]);
}
void solve(int l, int r)
{
    int len = 0, Start, End;
    int now = l;
    while(now<=r){
        int TStart = lower_bound(mp[1].begin(), mp[1].end(),now) - mp[1].begin();
        if(TStart==(int)mp[1].size()) break;
        TStart = mp[1][TStart];
        int TEnd = min(end1[TStart], r);
        int tem = TEnd - TStart+1;
        if(tem>len){
            len = tem;
            Start = TStart;
            End = TEnd;
        }
        now = TEnd+1;
    }
    printf("%d %d\n",Start, End);
}
int main()
{
    int tc,n,q,x,y;
    scanf("%d",&tc);
    for(int cs=1; cs<=tc; cs++){
        printf("Case %d:\n", cs);
        scanf("%d%d",&n,&q);
        for(int i=0; i<mx; i++)
            mp[i].clear();
        for(int i=1; i<=n; i++){
            scanf("%d",&arr[i]);
            mp[ arr[i] ].push_back(i);
        }
        build(n);
        while(q--){
            scanf("%d%d",&x,&y);
            int res = query(x,y);
            if(res==0)
                printf("0 %d %d\n",x,y);
            else if(res==1){
                printf("1 ");
                solve(x,y);
            }
            else{
                int ans = mp[res][lower_bound(mp[res].begin(), mp[res].end(), x) - mp[res].begin()];
                printf("%d %d %d\n",res,ans,ans);
            }
        }
    }
}