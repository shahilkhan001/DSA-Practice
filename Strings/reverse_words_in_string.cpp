/*
 * Problem: Reverse Words in a String
 *
 * Given an input string s, reverse the order of the words.
 * A word is defined as a sequence of non-space characters. The words in s 
 * will be separated by at least one space.
 * Return a string of the words in reverse order concatenated by a single space.
 * Note that s may contain leading or trailing spaces or multiple spaces between 
 * two words. The returned string should only have a single space separating the words.
 * Do not include any extra spaces.
 *
 * Example 1:
 * Input: s = "the sky is blue"
 * Output: "blue is sky the"
 *
 * Example 2:
 * Input: s = "  hello world  "
 * Output: "world hello"
 *
 * Example 3:
 * Input: s = "a good   example"
 * Output: "example good a"
 *
 * Constraints:
 * 1 <= s.length <= 10^4
 * s contains English letters (upper-case and lower-case), digits, and spaces ' '.
 * There is at least one word in s.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        stringstream ss(s);
        string word;
        
        while (ss >> word) {
            words.push_back(word);
        }
        
        reverse(words.begin(), words.end());
        
        string result;
        for (int i = 0; i < words.size(); i++) {
            if (i > 0) result += " ";
            result += words[i];
        }
        
        return result;
    }
};

// Driver Code for Testing
int main() {
    Solution sol;
    string s1 = "the sky is blue";
    string s2 = "  hello world  ";
    string s3 = "a good   example";

    cout << sol.reverseWords(s1) << endl; // Output: "blue is sky the"
    cout << sol.reverseWords(s2) << endl; // Output: "world hello"
    cout << sol.reverseWords(s3) << endl; // Output: "example good a"

    return 0;
}
