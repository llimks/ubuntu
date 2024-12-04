#include <iostream>
#include <cmath>
#include <cctype>
#include <stack>
#include <string>

using namespace std;

// Функція для обчислення факторіала
int factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

// Функція для обчислення пріоритету операторів
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '!') return 3; // факторіал має найвищий пріоритет
    return 0;
}

// Функція для виконання операцій
double applyOp(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: return 0;
    }
}

// Функція для обчислення виразу з урахуванням дужок
double evaluate(string expr) {
    stack<double> values;  // для чисел
    stack<char> ops;       // для операторів

    for (int i = 0; i < expr.length(); i++) {
        if (isspace(expr[i])) continue; // пропускаємо пробіли

        if (isdigit(expr[i])) { // якщо цифра, читаємо все число
            double val = 0;
            while (i < expr.length() && isdigit(expr[i])) {
                val = (val * 10) + (expr[i] - '0');
                i++;
            }
            values.push(val);
            i--; // повертаємо індекс на попередній символ
        }
        else if (expr[i] == '(') { // якщо дужки, додаємо до стека
            ops.push(expr[i]);
        }
        else if (expr[i] == ')') { // якщо закриваюча дужка, вирішуємо вираз
            while (!ops.empty() && ops.top() != '(') {
                char op = ops.top();
                ops.pop();

                double val2 = values.top();
                values.pop();
                double val1 = values.top();
                values.pop();

                values.push(applyOp(val1, val2, op));
            }
            ops.pop(); // видаляємо відкриваючу дужку
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

    // обчислюємо всі залишки
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

