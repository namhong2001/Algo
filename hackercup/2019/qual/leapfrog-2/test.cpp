#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main() {
    ifstream cin("./leapfrog_ch_.txt");
    ofstream cout("./junginout");
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": ";
        string s;
        cin >> s;
        // 뛰어넘은 개구리는 더이상 못쓰니까
        // 빈공간이랑 베타개구리랑 개수가 같거나..
        int blank = 0, beta = 0;
        string ret;
        for (auto &c:s) {
            if (c == 'B')
                beta++;
            else if (c == '.')
                blank++;
        }
        if(beta==0)
            ret="N";
        else if(blank==0)
            ret="N";
        else if(beta==1 && blank==1)
            ret="Y";
        else if(beta>=2)
            ret="Y";
        else
            ret="N";
        cout<<ret<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
