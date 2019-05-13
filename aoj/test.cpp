#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
/*
 * 알고리즘 문제 해결 전략 32장 - 네트워크 플로우
 */

using namespace std;
#define MAX_V 20

const int INF=987654321;
int N, M;
int wins[20], match[200][2];
int V;

int capacity[200][200], flow[200][200];
int networkFlow(int source, int sink){
    memset(flow, 0, sizeof(flow));
    int totalFlow=0;
    while(true){
        vector<int> parent(V, -1);
        queue<int> q;
        parent[source]=source;
        q.push(source);
        while(!q.empty() && parent[sink]==-1){
            int here=q.front(); q.pop();
            for(int there=0; there<V; ++there){
                if(capacity[here][there]-flow[here][there]>0 && parent[there]==-1){
                    q.push(there);
                    parent[there]=here;
                }
            }
        }
        if(parent[sink]==-1) break;
        int amount=INF;
        for(int p=sink; p!=source; p=parent[p])
            amount=min(capacity[parent[p]][p]-flow[parent[p]][p], amount);
        for(int p=sink; p!=source; p=parent[p]){
            flow[parent[p]][p]+=amount;
            flow[p][parent[p]]-=amount;
        }
        totalFlow+=amount;
    }
    return totalFlow;
}

bool canWinWith(int totalWins){
    if(*max_element(wins+1, wins+N)>=totalWins)
        return false;
    V=2+M+N;
    memset(capacity, 0, sizeof(capacity));
    for(int i=0; i<M; ++i){
        capacity[0][2+i]=1;
        for(int j=0; j<2; ++j){
            capacity[2+i][2+M+match[i][j]]=1;
        }
    }
    for(int i=0; i<N; ++i){
        int maxWin=(i==0?totalWins:totalWins-1);
        capacity[2+M+i][1]=maxWin-wins[i];
    }
    return networkFlow(0,1)==M;
}
int main() {
    int C;
    cin>>C;
    while(C--){
        cin>>N>>M;
        memset(wins, 0, sizeof(wins));
        memset(match, 0, sizeof(match));
        for(int i=0; i<N; ++i){
            cin>>wins[i];
        }
        int cnt=0;
        for(int j=0; j<M; ++j){
            int a, b;
            cin>>a>>b;
            match[j][0]=a;
            match[j][1]=b;
            if(a==0 || b==0) cnt++;
        }
        int ret=-1;
        for(int i=0; i<=cnt; ++i){
            if(canWinWith(wins[0]+i)){
                ret=i+wins[0];
                break;
            }
        }
        cout<<ret<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
