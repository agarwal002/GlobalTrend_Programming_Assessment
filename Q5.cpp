#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    void rotate(std::vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;  
        
      
        std::reverse(nums.begin(), nums.end());
        
        
        std::reverse(nums.begin(), nums.begin() + k);
        
    
        std::reverse(nums.begin() + k, nums.end());
    }
};

void printArray(const std::vector<int>& nums) {
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    Solution sol;
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    std::cout << "Original array: ";
    printArray(nums);

    sol.rotate(nums, k);

    std::cout << "Rotated array: ";
    printArray(nums);

    return 0;
}
