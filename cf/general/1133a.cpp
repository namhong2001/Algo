#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

int to_n(string s) {
    int h = stoi(s.substr(0, 2));
    int m = stoi(s.substr(3, 2));
    return h*60+m;
}

string to_s(int time) {
    int h = time/60;
    int m = time%60;
    stringstream ss;
    ss << setw(2) << setfill('0') << h;
    ss << ":";
    ss << setw(2) << setfill('0') << m;
    return ss.str();
}

int main() {
    string s, e;
    cin >> s >> e;
    int s_time = to_n(s);
    int e_time = to_n(e);
    int m_time = (s_time + e_time)/2;
    cout << to_s(m_time) << endl;
}
