#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(string expr) {
    stack<char> s;
    for (char c : expr) {
        if (c == '(' || c == '{' || c == '[')
            s.push(c);
        else if (c == ')' || c == '}' || c == ']') {
            if (s.empty()) return false;
            char top = s.top();
            if ((c == ')' && top == '(') ||
                (c == '}' && top == '{') ||
                (c == ']' && top == '[')) {
                s.pop();
            } else return false;
        }
    }
    return s.empty();
}

int main() {
    string expr = "{(a+b)*[c-d]}";
    if (isBalanced(expr))
        cout << "Balanced\n";
    else
        cout << "Not Balanced\n";
    return 0;
}