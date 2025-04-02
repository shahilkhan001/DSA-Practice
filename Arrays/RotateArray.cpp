/*
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

Example 1:
Input: nums = [1,2,3,4,5,6,7], k = 3 
Output: [5,6,7,1,2,3,4] 
Explanation: 
rotate 1 step to the right: [7,1,2,3,4,5,6] 
rotate 2 steps to the right: [6,7,1,2,3,4,5] 
rotate 3 steps to the right: [5,6,7,1,2,3,4] 

Example 2:
Input: nums = [-1,-100,3,99], k = 2 
Output: [3,99,-1,-100] 
Explanation:  
rotate 1 step to the right: [99,-1,-100,3] 
rotate 2 steps to the right: [3,99,-1,-100] 

Constraints:
1 <= nums.length <= 10^5
-2^31 <= nums[i] <= 2^31 - 1
0 <= k <= 10^5
*/

#include <iostream>
#include <vector>
#include <algorithm>  // for reverse function

using namespace std;

void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k %= n; // In case k > n

    reverse(nums.begin(), nums.end());           // Step 1: Reverse the whole array
    reverse(nums.begin(), nums.begin() + k);     // Step 2: Reverse the first k elements
    reverse(nums.begin() + k, nums.end());       // Step 3: Reverse the remaining elements
}

// Function to print the rotated array
void printArray(const vector<int>& nums) {
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

// Test the function
int main() {
    vector<int> nums = {1,2,3,4,5,6,7};
    int k = 3;

    rotate(nums, k);

    cout << "Rotated Array: ";
    printArray(nums);

    return 0;
}
