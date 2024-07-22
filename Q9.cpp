#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

class Solution {
public:
    int maxDifference(const std::vector<int>& nums) {
        if (nums.size() < 2) {
            std::cerr << "Array should have at least two elements." << std::endl;
            return -1;  
        }

        int minElement = INT_MAX;
        int maxElement = INT_MIN;

        for (int num : nums) {
            if (num < minElement) {
                minElement = num;
            }
            if (num > maxElement) {
                maxElement = num;
            }
        }

        return maxElement - minElement;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums = {1, 2, 90, 10, 110};

    int result = sol.maxDifference(nums);
    std::cout << "Maximum difference between any two elements in the array is: " << result << std::endl;

    return 0;
}
