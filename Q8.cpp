#include <iostream>

class Solution {
public:
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
};

int main() {
    Solution sol;
    int a, b;

    std::cout << "Enter two numbers: ";
    std::cin >> a >> b;

    int result = sol.gcd(a, b);
    std::cout << "GCD of " << a << " and " << b << " is: " << result << std::endl;

    return 0;
}
