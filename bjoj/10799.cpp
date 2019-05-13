#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    stack<string> my_stack;
    string input_str;
    cin >> input_str;
    int sum = 0;
    for (int i=0; i<input_str.size(); ++i) {
        string bracket(1, input_str[i]);
        if (bracket == "(") {
            my_stack.push(bracket);
        } else {
            if (my_stack.top() == "(") {
                my_stack.pop();

                if (my_stack.empty()) continue;

                if (my_stack.top() == "(") {
                    my_stack.push("1");
                } else {
                    int lazer_cnt = stoi(my_stack.top());
                    lazer_cnt++;
                    my_stack.pop();
                    my_stack.push(to_string(lazer_cnt));
                }
            } else {
                int top = stoi(my_stack.top());
                sum += top + 1;
                my_stack.pop();
                if (my_stack.size() > 0) {
                    my_stack.pop();
                }
                while (my_stack.size() > 0 && my_stack.top() != "(") {
                    top += stoi(my_stack.top());
                    my_stack.pop();
                }
                if (my_stack.size() > 0) {
                    my_stack.push(to_string(top));
                }
            }
        }
//        if (!my_stack.empty()) {
//            cout << my_stack.size() << ' ' <<  my_stack.top() << endl;
//        }
    }
    cout << sum;
    return 0;
}
