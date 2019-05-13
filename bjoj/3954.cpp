#include <iostream>
#include <vector>
#include <stack>
#include <sstream>

using namespace std;

vector<char> memory;
string code, input;
int pointer;
int code_pos;
int code_last_pos;
int input_pos;
int perform_cnt;
vector<int> jump;

void perform(char action) {
    ++perform_cnt;
    switch(action) {
    case '-':
        memory[pointer]--;
        return;
    case '+':
        memory[pointer]++;
        return;
    case '<':
        pointer--;
        if (pointer < 0) pointer += memory.size();
        return;
    case '>':
        pointer++;
        if (pointer >= memory.size()) pointer -= memory.size();
        return;
    case '[':
        if (memory[pointer] == 0) {
            code_pos = jump[code_pos];
        }
        return;
    case ']':
        if (memory[pointer] != 0) {
            if (code_pos > code_last_pos) {
                code_last_pos = code_pos;
            }
            code_pos = jump[code_pos];
        }
        return;
    case '.':
        // do nothing
        return;
    case ',':
        if (input_pos == input.size()) {
            memory[pointer] = 255;
        } else {
            memory[pointer] = input[input_pos++];
        }
        return;
    }
}

string solve() {
    for (; code_pos<code.size(); ++code_pos) {
        char action = code[code_pos];
        perform(action);
        if (perform_cnt > 50000000) {
            ostringstream oss;
            oss << "Loops " << jump[code_last_pos] << " " << code_last_pos;
            return oss.str();
        }
    }
    return "Terminates";
}

void init_jump() {
    stack<int> bracket_pos;
    for (int i=0; i<code.size(); ++i) {
        if (code[i] == '[') {
            bracket_pos.push(i);
        } else if (code[i] == ']') {
            int left = bracket_pos.top();
            bracket_pos.pop();
            jump[left] = i;
            jump[i] = left;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int sm, sc, si;
        cin >> sm >> sc >> si;
        cin >> code >> input;
        memory = vector<char>(sm, 0);
        jump = vector<int>(sc);
        pointer = 0;
        code_pos = 0;
        code_last_pos = -1;
        input_pos = 0;
        perform_cnt = 0;
        init_jump();
        cout << solve() << endl;
    }

    return 0;
}
