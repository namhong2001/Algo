#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<string> category_arr;
        vector<int> cloth_count_arr;
        while (n--) {
            string name;
            string category;
            cin >> name >> category;
            bool category_exist = false;
            for (int i=0; i<category_arr.size(); ++i) {
                if (category_arr[i] == category) {
                    cloth_count_arr[i]++;
                    category_exist = true;
                    break;
                }
            }
            if (category_exist == false) {
                category_arr.push_back(category);
                cloth_count_arr.push_back(1);
            }
        }
        int ret;
        if (cloth_count_arr.empty()) ret = 0;
        else {
            ret = 1;
            for (auto i : cloth_count_arr) {
                ret *= i+1;
            }
            ret -= 1;
        }
        cout << ret << '\n';
    }


    return 0;
}
