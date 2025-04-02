/*
 * Problem: Convert Integer to Roman
 * 
 * Given an integer, convert it to a Roman numeral.
 *
 * Roman numerals are represented by seven different symbols: I, V, X, L, C, D, and M.
 * The numeral system follows subtractive notation for numbers like 4 (IV), 9 (IX), 40 (XL), etc.
 * 
 * Example 1:
 * Input: num = 3749
 * Output: "MMMDCCXLIX"
 *
 * Example 2:
 * Input: num = 58
 * Output: "LVIII"
 *
 * Example 3:
 * Input: num = 1994
 * Output: "MCMXCIV"
 *
 * Constraints:
 * 1 <= num <= 3999
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> roman = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        };

        string result = "";
        for (auto &pair : roman) {
            while (num >= pair.first) {
                result += pair.second;
                num -= pair.first;
            }
        }
        return result;
    }
};

// Driver Code for Testing
int main() {
    Solution sol;
    cout << sol.intToRoman(3749) << endl; // Output: "MMMDCCXLIX"
    cout << sol.intToRoman(58) << endl;   // Output: "LVIII"
    cout << sol.intToRoman(1994) << endl; // Output: "MCMXCIV"
    return 0;
}
