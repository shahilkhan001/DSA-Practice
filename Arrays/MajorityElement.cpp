/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times.
You may assume that the majority element always exists in the array.

Example 1:
Input: nums = [3,2,3] 
Output: 3 

Example 2:
Input: nums = [2,2,1,1,1,2,2] 
Output: 2 

Constraints:
n == nums.length
1 <= n <= 5 * 10^4
-10^9 <= nums[i] <= 10^9
*/

#include <iostream>
#include <vector>

using namespace std;

int majorityElement(vector<int>& nums) {
    int candidate = nums[0], count = 1;

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == candidate) {
            count++;
        } else {
            count--;
            if (count == 0) {
                candidate = nums[i];
                count = 1;
            }
        }
    }

    return candidate;
}

// Test the function
int main() {
    vector<int> nums = {2,2,1,1,1,2,2};

    int result = majorityElement(nums);

    cout << "Majority Element: " << result << endl;

    return 0;
}
