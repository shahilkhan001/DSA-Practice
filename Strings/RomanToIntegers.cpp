/*
 * Roman numerals are represented by seven different symbols:
 * I, V, X, L, C, D, and M.
 * 
 * Symbol       Value
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 *
 * Given a Roman numeral string, convert it to an integer.
 *
 * Example 1:
 * Input: s = "III"
 * Output: 3
 *
 * Example 2:
 * Input: s = "LVIII"
 * Output: 58
 *
 * Example 3:
 * Input: s = "MCMXCIV"
 * Output: 1994
 *
 * Constraints:
 * 1 <= s.length <= 15
 * s contains only ('I', 'V', 'X', 'L', 'C', 'D', 'M').
 * It is guaranteed that s is a valid Roman numeral in the range [1, 3999].
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, 
            {'C', 100}, {'D', 500}, {'M', 1000}
        };
        
        int result = 0;
        int n = s.length();
        
        for (int i = 0; i < n; i++) {
            if (i < n - 1 && roman[s[i]] < roman[s[i + 1]]) {
                result -= roman[s[i]];
            } else {
                result += roman[s[i]];
            }
        }
        return result;
    }
};

// Driver Code
int main() {
    Solution sol;
    string s = "MCMXCIV";
    cout << sol.romanToInt(s) << endl; // Output: 1994
    return 0;
}
