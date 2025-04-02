/*
You are given an integer array nums. You are initially positioned at the array's first index, 
and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

Example 1:
Input: nums = [2,3,1,1,4] 
Output: true 
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:
Input: nums = [3,2,1,0,4] 
Output: false 
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, 
which makes it impossible to reach the last index.

Constraints:
1 <= nums.length <= 10^4
0 <= nums[i] <= 10^5
*/

#include <iostream>
#include <vector>

using namespace std;

bool canJump(vector<int>& nums) {
    int maxReach = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (i > maxReach) return false;  // If we can't reach index i, return false
        maxReach = max(maxReach, i + nums[i]);  // Update maxReach
    }
    return true;
}

// Function to test canJump
int main() {
    vector<int> nums1 = {2,3,1,1,4};
    vector<int> nums2 = {3,2,1,0,4};
    
    cout << "Can reach last index (nums1): " << (canJump(nums1) ? "true" : "false") << endl;  // Expected: true
    cout << "Can reach last index (nums2): " << (canJump(nums2) ? "true" : "false") << endl;  // Expected: false

    return 0;
}
