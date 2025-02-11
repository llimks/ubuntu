#include <iostream>

void printPascalsTriangle(int n) {
    for (int i = 0; i < n; i++) {
        int num = 1;
        for (int j = 0; j <= i; j++) {
            std::cout << num << " ";
            num = num * (i - j) / (j + 1);
        }
        std::cout << std::endl;
    }
}

int main() {
    int n;
    std::cout << "Enter the number of rows for Pascal's Triangle: ";
    std::cin >> n;
    printPascalsTriangle(n);
    return 0;
}

