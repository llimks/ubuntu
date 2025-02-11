#include <iostream>
#include <vector>

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;

    for (int i = n; i <= 2 * n; ++i) {
        if (isPrime(i) && isPrime(i + 2)) {
            std::cout << "(" << i << ", " << i + 2 << ")\n";
        }
    }

    return 0;
}

