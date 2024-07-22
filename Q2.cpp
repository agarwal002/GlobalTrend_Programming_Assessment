#include <iostream>
#include <unordered_map>
#include <string>

class Solution {
public:
    int lengthOfLongestSubstring(const std::string& s) {
        std::unordered_map<char, int> charIndexMap;
        int maxLength = 0, start = 0;

        for (int i = 0; i < s.length(); ++i) {
            if (charIndexMap.find(s[i]) != charIndexMap.end() && charIndexMap[s[i]] >= start) {
                start = charIndexMap[s[i]] + 1;
            }
            charIndexMap[s[i]] = i;
            maxLength = std::max(maxLength, i - start + 1);
        }

        return maxLength;
    }
};

int main() {
    Solution sol;
    std::string str = "abcabcbb";
    
    int result = sol.lengthOfLongestSubstring(str);
    std::cout << "Length of the longest substring without repeating characters: " << result << std::endl;

    return 0;
}
