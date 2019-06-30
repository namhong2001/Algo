#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream cin("./leapfrog_ch_.txt");
    ofstream cout("./jungin_output.txt");
    int T;
    cin>>T;
    for(int t=1; t<=T; ++t){
        cout<<"Case #"<<t<<": ";
        string s;
        cin>>s;
        // 뛰어넘은 개구리는 더이상 못쓰니까
        // 빈공간이랑 베타개구리랑 개수가 같거나..
        int blank=0, beta=0;
        for(auto &c:s){
            if(c=='B')
                beta++;
            else if(c=='.')
                blank++;
        }
        if(blank!=0 && beta>=blank) {
            cout<<"Y"<<'\n';
        }
        else
            cout<<"N"<<'\n';

    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
