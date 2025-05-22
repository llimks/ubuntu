#include <iostream>
#include <string>
using namespace std;

string toBinary(int number) {
    string result = "";
    if (number == 0) return "0";
    while (number > 0) {
        result = to_string(number % 2) + result;
        number = number / 2;
    }
    return result;
}

int main() {
    int a = 255, b = 1024, c = 364;

    cout << "Decimal to Binary and Hex:\n";
    cout << a << " = Binary: " << toBinary(a) << ", Hex: " << hex << a << endl;
    cout << dec << b << " = Binary: " << toBinary(b) << ", Hex: " << hex << b << endl;
    cout << dec << c << " = Binary: " << toBinary(c) << ", Hex: " << hex << c << endl;

    cout << "\nBinary to Decimal:\n";
    cout << "011001 = " << stoi("011001", 0, 2) << endl;
    cout << "011100111 = " << stoi("011100111", 0, 2) << endl;
    cout << "111000 = " << stoi("111000", 0, 2) << endl;

    cout << "\nHex to Decimal:\n";
    cout << "1FF = " << stoi("1FF", 0, 16) << endl;
    cout << "94 = " << stoi("94", 0, 16) << endl;
    cout << "FF = " << stoi("FF", 0, 16) << endl;

    return 0;
}

