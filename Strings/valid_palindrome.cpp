/*
 * Problem: Valid Palindrome
 *
 * A phrase is a palindrome if, after converting all uppercase letters 
 * into lowercase letters and removing all non-alphanumeric characters, 
 * it reads the same forward and backward. Alphanumeric characters include 
 * letters and numbers.
 *
 * Given a string s, return true if it is a palindrome, or false otherwise.
 *
 * Example 1:
 * Input: s = "A man, a plan, a canal: Panama"
 * Output: true
 * Explanation: "amanaplanacanalpanama" is a palindrome.
 *
 * Example 2:
 * Input: s = "race a car"
 * Output: false
 * Explanation: "raceacar" is not a palindrome.
 *
 * Example 3:
 * Input: s = " "
 * Output: true
 * Explanation: s is an empty string "" after removing non-alphanumeric 
 * characters. Since an empty string reads the same forward and backward, 
 * it is a palindrome.
 *
 * Constraints:
 * 1 <= s.length <= 2 * 10^5
 * s consists only of printable ASCII characters.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string filtered;
        
        // Convert to lowercase and remove non-alphanumeric characters
        for (char c : s) {
            if (isalnum(c)) {
                filtered += tolower(c);
            }
        }
        
        // Check if the filtered string is a palindrome
        int left = 0, right = filtered.size() - 1;
        while (left < right) {
            if (filtered[left] != filtered[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};

// Driver Code for Testing
int main() {
    Solution sol;
    cout << sol.isPalindrome("A man, a plan, a canal: Panama") << endl; // Output: true
    cout << sol.isPalindrome("race a car") << endl; // Output: false
    cout << sol.isPalindrome(" ") << endl; // Output: true

    return 0;
}
