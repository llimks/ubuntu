#include <iostream>

void sieve(int n) {
    bool isPrime[n + 1];

    for (int i = 0; i <= n; ++i) {
        isPrime[i] = true;
    }

    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= n; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        if (isPrime[i]) {
            std::cout << i << " ";
        }
    }
}

int main() {
    int n = 1000;
    std::cout << "Prime numbers up to " << n << ": ";
    sieve(n);
    return 0;
}

