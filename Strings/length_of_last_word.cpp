/*
 * Problem: Length of Last Word
 * 
 * Given a string s consisting of words and spaces, return the length of the last word in the string.
 * A word is a maximal substring consisting of non-space characters only.
 *
 * Example 1:
 * Input: s = "Hello World"
 * Output: 5
 *
 * Example 2:
 * Input: s = "   fly me   to   the moon  "
 * Output: 4
 *
 * Example 3:
 * Input: s = "luffy is still joyboy"
 * Output: 6
 *
 * Constraints:
 * 1 <= s.length <= 10^4
 * s consists of only English letters and spaces ' '.
 * There will be at least one word in s.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        int i = s.size() - 1;

        // Remove trailing spaces
        while (i >= 0 && s[i] == ' ') i--;

        // Count the last word's length
        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }

        return length;
    }
};

// Driver Code for Testing
int main() {
    Solution sol;
    cout << sol.lengthOfLastWord("Hello World") << endl;           // Output: 5
    cout << sol.lengthOfLastWord("   fly me   to   the moon  ") << endl; // Output: 4
    cout << sol.lengthOfLastWord("luffy is still joyboy") << endl; // Output: 6
    return 0;
}
