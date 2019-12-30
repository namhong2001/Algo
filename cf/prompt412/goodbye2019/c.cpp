#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Com
{
    int ti, o;
};

int N, Q;
vector<bool> arr;
// vector<Com> com;
// stack<int> com;
stack<Com> com;

// int lasti = 0;

// int rev(int ci, int ti) {
//     for (int i=ci-1; i>ti; --i) {
//         if (com[i].a == 3) continue;
//         if (com[i].a == 2) continue; // TODO: immpl
//         if (com[i].a == 1) doaction(ci, 1, ti);
//     }
// };

// int doaction(int ci, int a, int ti) {
//     if (a == 1) {
//         arr[ti] = !arr[ti];
//     } else if (a == 2) {
//         if (lasti == 0) rev(ci, ti);
//         else {
//             rev(ci, lasti);
//             rev(lasti, ti);
//         } 
//     } else if (a == 3) {
//         cout << arr[ti] << '\n';
//     }
// };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    
    cin >> N >> Q;
    arr.assign(N+1, 0);
    // com.resize(Q+1);

    for (int i = 1; i <= Q; ++i)
    {
        int a, ti;
        cin >> a >> ti;
        if (a == 1) {
            arr[ti] = !arr[ti];
            com.push({ti, i});
        } else if (a == 2) {
            while (!com.empty() && com.top().o > ti) {
                const Com c = com.top();
                com.pop();
                arr[c.ti] = !arr[c.ti];
            }
        } else if (a == 3) {
            cout << arr[ti] << '\n';
        }
    }
    return 0;
}