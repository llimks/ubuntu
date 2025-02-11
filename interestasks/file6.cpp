#include <iostream>
#include <string>

std::string numberToWords(int n) {
    const std::string ones[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    const std::string teens[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    const std::string tens[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    const std::string hundreds[] = {"", "one hundred", "two hundred", "three hundred", "four hundred", "five hundred", "six hundred", "seven hundred", "eight hundred", "nine hundred"};

    if (n == 1000) return "one thousand";

    std::string result = "";

    if (n >= 100) {
        result += hundreds[n / 100];
        n %= 100;
        if (n > 0) result += " ";
    }

    if (n >= 10 && n < 20) {
        result += teens[n - 10];
    } else {
        if (n >= 20) {
            result += tens[n / 10];
            n %= 10;
            if (n > 0) result += " ";
        }
        if (n > 0) {
            result += ones[n];
        }
    }

    return result;
}

int main() {
    int n;
    std::cout << "Enter a number (<= 1000): ";
    std::cin >> n;
    std::cout << "The number in words: " << numberToWords(n) << std::endl;
    return 0;
}

