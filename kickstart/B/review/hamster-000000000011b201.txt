#include <iostream>

using namespace std;

int N, Q;
string S;
int cnt[26][100001];

int where(){
    int l=0, r=N-1;
    while(S[l]==S[r]){
        l++;
        r--;
    }
}
bool solve(int l, int r){
    // 짝수
    int n=r-l+1;
    if(n%2==0){
        for(int i=0; i<26; ++i){
            int count=cnt[i][r]-cnt[i][l-1];
            if(count%2!=0)
                return false;
        }
        return true;
    }
    bool flag=true;
    if(n%2==1){
        for(int i=0; i<26; ++i){
            int count=cnt[i][r]-cnt[i][l-1];
            if(count%2!=0 && flag){
                flag=false;
            }
            else if(count%2!=0){
                return false;
            }
        }
        return true;
    }
}

int main() {
    int T;
    cin>>T;
    for(int t=1; t<=T; ++t){
        cin>>N>>Q>>S;
        int ret=0;
        for(int i=1; i<=N; ++i){
            char c=S[i-1];
            for(int j=0; j<26; ++j){
                cnt[j][i]=cnt[j][i-1];
            }
            cnt[c-'A'][i]=cnt[c-'A'][i-1]+1;
        }
        for(int i=0; i<Q; ++i){
            int l, r;
            cin>>l>>r;
            ret+=solve(l, r);
        }
        cout<<"Case #"<<t<<": "<<ret<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}