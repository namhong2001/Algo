/*
[BOJ] 1543. 문서검색
*/  
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

string str, word;
bool check[2501];

int main()
{
    io;
    getline(cin, str);
    getline(cin, word);
    int wlen = word.length(), cnt = 0, ans = 0, slen = str.length();
    if(wlen > slen){
        cout<<"0\n";
        return 0;
    }
    for(int i=0;i<slen;i++){
        if(str[i] == word[cnt]){
            if(cnt == wlen - 1) {
                ans++;
                cnt = 0;
                continue;
            } else if(str[i+1] != word[cnt+1]) {
                cnt = 0;
                if(str[i] == word[cnt]) cnt++;
                continue;
            }
            check[i] += 1;
            cnt++;
        }else{
            cnt = 0;
            if(str[i] == word[cnt]){
                cnt++;
            }
        }
    }
    cout<<ans<<"\n";

    return 0;
}