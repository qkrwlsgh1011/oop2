#include <iostream>
#include <string>
#include <stack>
using namespace std;

int precedence(char c) {
    if (c == '+')
        return 0;
    else
        return 1;
}

int evaluate(string str) {
    stack<int> stk;
    int x, y;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != '+' && str[i] != '*')
            stk.push(str[i] - '0');
        else {
            x = stk.top();
            stk.pop();
            y = stk.top();
            stk.pop();
            if (str[i] == '+') {
                stk.push(x + y);
            }
            else {
                stk.push(x * y);
            }
        }
    }

    return (stk.top());
}

string to_postfix(string str) {
    stack<char> stk;
    string postfix = "";
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != '+' && str[i] != '*')
            postfix += str[i];
        else {
            if (stk.empty())
                stk.push(str[i]);
            else {
                if (str[i] == '*' && stk.top() == '+')
                    stk.push(str[i]);
                else {
                    while (!stk.empty() && precedence(str[i]) <= precedence(stk.top())) {
                        postfix += stk.top();
                        stk.pop();
                    }
                    stk.push(str[i]);
                }
            }
        }
    }

    while (!stk.empty()) {
        postfix += stk.top();
        stk.pop();
    }

    return postfix;
}

int main() {
    int cmd, m, n, right, op, ran_op, res;
    char x;
    bool flag;
    char* left;
    cin >> cmd;
    string infix;
    string postfix;

    while (cmd--) {
        cin >> m >> n;
        while (m--) {
            left = new char[n];

            for (int i = 0; i < n; i++) {
                cin >> x;
                left[i] = x;
            }
            cin >> right;

            infix = "";
            for (int i = 0; i < n; i++) {
                infix += char(left[i]);
                if (i != n - 1)
                    infix += " ";
            }

            op = 1;
            for (int i = 0; i < n - 1; i++) {
                op *= 2;
            }
            op--;

            flag = false;
            while (op >= 0) {
                ran_op = 1;

                for (int i = 0; i < n - 1; i++) {
                    if (op & ran_op)
                        infix[i * 2 + 1] = '+';
                    else
                        infix[i * 2 + 1] = '*';
                    ran_op = ran_op << 1;
                }

                postfix = to_postfix(infix);
                res = evaluate(postfix);

                if (res == right) {
                    flag = true;
                    break;
                }

                op--;
            }

            if (flag)
                cout << "1 ";
            else
                cout << "0 ";
            delete[] left;
        }
        cout << endl;
    }
    return 0;
}