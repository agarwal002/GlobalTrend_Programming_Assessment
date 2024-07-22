#include <iostream>

class Solution {
public:
    int factorial(int n) {
        if (n < 0) {
            std::cerr << "Factorial is not defined for negative numbers." << std::endl;
            return -1;
        }
        int result = 1;
        for (int i = 1; i <= n; ++i) {
            result *= i;
        }
        return result;
    }
};

int main() {
    Solution sol;
    int number;

    std::cout << "Enter a number: ";
    std::cin >> number;

    int result = sol.factorial(number);
    if (result != -1) {
        std::cout << "Factorial of " << number << " is: " << result << std::endl;
    }

    return 0;
}
