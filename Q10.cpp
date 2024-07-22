#include <iostream>
#include <string>

class Solution {
public:
    bool isAlphabetic(const std::string& str) {
        for (char c : str) {
            if (!isalpha(c)) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    std::string input;

    std::cout << "Enter a string: ";
    std::cin >> input;

    bool result = sol.isAlphabetic(input);
    if (result) {
        std::cout << "The string contains only alphabetic characters." << std::endl;
    } else {
        std::cout << "The string contains non-alphabetic characters." << std::endl;
    }

    return 0;
}
