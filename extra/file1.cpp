#include <iostream>

int main()
 { int m, n;
    std::cout << "Enter m (rows): ";
    std::cin >> m;
    std::cout << "Enter n (columns): ";
    std::cin >> n;

   if (m < 0 || m > 100 || n < 0 || n > 100) {
    std::cout << "m and n must be between 0 and 100." << std::endl;
    return 1;
    }

    int matrix[m][n];
    int num = 1;

    for (int i = 0; i < m; i++) {
      if (i % 2 == 0) {
          for (int j = 0; j < n; j++)
 { matrix[i][j] = num++;
            }
      } else {
          for (int j = n - 1; j >= 0; j--)
 {  matrix[i][j] = num++;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << matrix[i][j] << " \t";
        }
        std::cout << std::endl;
    }

    return 0;
}

