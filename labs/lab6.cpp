
#include <iostream>
#include <cmath>
using namespace std;

void task1() {
    int N;
    cout << "Enter number of terms N: ";
    cin >> N;

    double sum = 0;
    for (int i = 0; i < N; ++i) {
        double numerator = pow(3, i);
        double denominator = pow(3, i) + (3 * i);
        double term = numerator / denominator;
        sum += term;
        cout << "Term " << i + 1 << ": " << term << endl;
    }

    cout << "Final sum: " << sum << endl;
}

void task2() {
    const double a = 0.8 * M_PI;
    for (double x = -1.0; x <= 2.0; x += 0.2) {
        double y;
        if (x < 0) {
            y = x * x + 1;
        } else if (x > 1.4) {
            y = x - 2.1;
        } else {
            y = cos(a * x);
        }
        cout << "x = " << x << ", y = " << y << endl;
    }
}

void task3() {
    const double a = 0.2;
    for (double x = -2.0; x <= 2.0; x += 0.5) {
        double z;
        if (x <= 0.5) {
            z = (x * x - 5 * x + 6) / (x * x + 1);
        } else {
            double part = cbrt(pow(x, 3) - pow(x, 2)) + exp(a);
            z = 1.0 / part;
        }
        cout << "x = " << x << ", z = " << z << endl;
    }
}

int main() {
    int taskNumber;

    while (true) {
        cout << "\nEnter task number (1, 2, 3) or 0 to exit: ";
        cin >> taskNumber;

        if (taskNumber == 0) break;

        switch (taskNumber) {
            case 1:
                task1();
                break;
            case 2:
                task2();
                break;
            case 3:
                task3();
                break;
            default:
                cout << "Invalid task number.\n";
        }
    }

    cout << "Program finished." << endl;
    return 0;
}

