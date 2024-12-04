#include <iostream>
#include <cmath>
#include <cctype>
#include <stack>
#include <string>

using namespace std;

int factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '!') return 3;
    return 0;
}

double applyOp(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: return 0;
    }
}

double evaluate(string expr) {
    stack<double> values; 
    stack<char> ops;       

    for (int i = 0; i < expr.length(); i++) {
        if (isspace(expr[i])) continue; 

        if (isdigit(expr[i])) { 
            double val = 0;
            while (i < expr.length() && isdigit(expr[i])) {
                val = (val * 10) + (expr[i] - '0');
                i++;
            }
            values.push(val);
            i--; 
        }
        else if (expr[i] == '(') { 
            ops.push(expr[i]);
        }
        else if (expr[i] == ')') {
            while (!ops.empty() && ops.top() != '(') {
                char op = ops.top();
                ops.pop();

                double val2 = values.top();
                values.pop();
                double val1 = values.top();
                values.pop();

                values.push(applyOp(val1, val2, op));
            }
            ops.pop();
        }
        else if (expr[i] == '!') { // факторіал
            int val = values.top();
            values.pop();
            values.push(factorial(val));
        }
        else { // оператори +, -, *, /
            while (!ops.empty() && precedence(ops.top()) >= precedence(expr[i])) {
                char op = ops.top();
                ops.pop();

                double val2 = values.top();
                values.pop();
                double val1 = values.top();
                values.pop();

                values.push(applyOp(val1, val2, op));
            }
            ops.push(expr[i]);
        }
    }

    while (!ops.empty()) {
        char op = ops.top();
        ops.pop();

        double val2 = values.top();
        values.pop();
        double val1 = values.top();
        values.pop();

        values.push(applyOp(val1, val2, op));
    }

    return values.top();
}

int main() {
    string expr;
    cout << "Enter a mathematical expression: ";
    getline(cin, expr);

    cout << "Result: " << evaluate(expr) << endl;

    return 0;
}
