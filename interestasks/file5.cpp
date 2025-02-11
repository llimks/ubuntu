#include <iostream>

bool isPalindrome(int n) {
    int reversed = 0, original = n;
    while (n) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    return original == reversed;
}

int main() {
    for (int i = 1; i <= 99; ++i)
        if (isPalindrome(i) && isPalindrome(i * i))
            std::cout << i << " (square: " << i * i << ")\n";
    return 0;
}

