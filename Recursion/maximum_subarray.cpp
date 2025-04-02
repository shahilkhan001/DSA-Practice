/*
 * Given an integer array nums, find the contiguous subarray (containing at least one number) 
 * which has the largest sum and return its sum.
 * 
 * Example 1:
 * Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
 * Output: 6
 * Explanation: The subarray [4,-1,2,1] has the largest sum 6.
 * 
 * Example 2:
 * Input: nums = [1]
 * Output: 1
 * Explanation: The subarray [1] has the largest sum 1.
 * 
 * Example 3:
 * Input: nums = [5,4,-1,7,8]
 * Output: 23
 * Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
 * 
 * Constraints:
 * - 1 <= nums.length <= 10^5
 * - -10^4 <= nums[i] <= 10^4
 * 
 * Follow-up: If you have figured out the O(n) solution, try coding another solution using 
 * the divide and conquer approach, which is more subtle.
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0]; // Initialize max sum with first element
        int currentSum = nums[0]; // Initialize current sum with first element
        
        for (int i = 1; i < nums.size(); i++) {
            currentSum = max(nums[i], currentSum + nums[i]); // Extend or start new subarray
            maxSum = max(maxSum, currentSum); // Update max sum if needed
        }
        
        return maxSum;
    }
};

int main() {
    // Example: nums = [-2,1,-3,4,-1,2,1,-5,4]
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    
    Solution sol;
    int result = sol.maxSubArray(nums);
    
    cout << "Maximum Subarray Sum: " << result << endl; // Expected Output: 6
    
    return 0;
}
