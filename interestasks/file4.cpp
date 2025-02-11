#include <iostream>

void primeFactors(int n) {
    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            std::cout << i << ", ";
            n /= i;
        }
    }
    if (n > 1) {
        std::cout << n;
    }
}

int main() {
    int n = 250;
    std::cout << "Prime factors of " << n << " are: ";
    primeFactors(n);
    return 0;
}

