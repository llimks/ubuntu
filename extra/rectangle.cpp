#include <iostream>

int main() {
    int m, n;
    std::cout << "Enter number of rows (m): ";
    std::cin >> m;
    std::cout << "Enter number of columns (n): ";
    std::cin >> n;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    return 0;
}

