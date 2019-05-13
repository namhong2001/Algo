#include <iostream>
#include <deque>

using namespace std;

int *split(string s, int n)
{
    int a = 0;
    bool minus_flag = false;
    bool has_decimal = false;
    int *ret = new int[n];
    int pos = 0;
    for (auto i : s)
    {
        if (i == '-')
        {
            minus_flag = true;
        }
        else if (i >= '0' && i <= '9')
        {
            a = a * 10 + (i - '0');
            has_decimal = true;
        }
        else
        {
            if (has_decimal)
            {
                ret[pos] = a * (minus_flag ? -1 : 1);
                a = 0;
                minus_flag = false;
                has_decimal = false;
                pos++;
            }
        }
    }
    return ret;
}
void print_array(int* arr, int start, int end, bool is_front) {
    cout << '[';
    if (is_front) {
        for (int i=start; i<end; ++i) {
            cout << arr[i];
            if (i < end-1) {
                cout << ',';
            }
        }
    } else {
        for (int i=end-1; i>start-1; --i) {
            cout << arr[i];
            if (i > start) {
                cout << ',';
            }
        }
    }

    cout << ']' << '\n';
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string command;
        cin >> command;
        int n;
        cin >> n;

        string arr_str;
        cin >> arr_str;
        int *arr = split(arr_str, n);


        bool is_front = true;
        int front_pos = 0;
        int back_pos = n;
        for (auto i : command)
        {
            if (i == 'R')
            {
                is_front = !is_front;
            }
            else if (i == 'D')
            {
                if (is_front) {
                    front_pos++;
                } else {
                    back_pos--;
                }
            }
        }
        if (front_pos > back_pos) {
            cout << "error" << '\n';
        } else {
            print_array(arr, front_pos, back_pos, is_front);
        }
    }

    return 0;
}
