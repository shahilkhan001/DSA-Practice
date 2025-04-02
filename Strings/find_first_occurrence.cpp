/*
 * Problem: Find the First Occurrence of a Substring
 *
 * Given two strings needle and haystack, return the index of the 
 * first occurrence of needle in haystack, or -1 if needle is not part 
 * of haystack.
 *
 * Example 1:
 * Input: haystack = "sadbutsad", needle = "sad"
 * Output: 0
 * Explanation: "sad" occurs at index 0 and 6. The first occurrence 
 * is at index 0, so we return 0.
 *
 * Example 2:
 * Input: haystack = "leetcode", needle = "leeto"
 * Output: -1
 * Explanation: "leeto" did not occur in "leetcode", so we return -1.
 *
 * Constraints:
 * 1 <= haystack.length, needle.length <= 10^4
 * haystack and needle consist of only lowercase English characters.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle);
    }
};

// Driver Code for Testing
int main() {
    Solution sol;
    cout << sol.strStr("sadbutsad", "sad") << endl; // Output: 0
    cout << sol.strStr("leetcode", "leeto") << endl; // Output: -1

    return 0;
}
