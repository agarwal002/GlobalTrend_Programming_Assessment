#include <iostream>

class Solution {
public:
    int sumOfDigits(int num) {
        int sum = 0;
        while (num != 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
};

int main() {
    Solution sol;
    int number;

    std::cout << "Enter a number: ";
    std::cin >> number;

    int result = sol.sumOfDigits(number);
    std::cout << "Sum of the digits of " << number << " is: " << result << std::endl;

    return 0;
}
