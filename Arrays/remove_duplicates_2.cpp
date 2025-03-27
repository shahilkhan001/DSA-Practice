/*
Given an integer array nums sorted in non-decreasing order, remove some duplicates in-place 
such that each unique element appears at most twice. The relative order of the elements should be kept the same.

Since it is impossible to change the length of the array in some languages, you must instead have 
the result be placed in the first part of the array nums. More formally, if there are k elements 
after removing the duplicates, then the first k elements of nums should hold the final result. 
It does not matter what you leave beyond the first k elements.

You must do this by modifying the input array in-place with O(1) extra memory.

Custom Judge:
The judge will test your solution with the following code:

    int[] nums = [...]; // Input array 
    int[] expectedNums = [...]; // The expected answer with correct length  
    int k = removeDuplicates(nums); // Calls your implementation  
    assert k == expectedNums.length; 
    for (int i = 0; i < k; i++) {     
        assert nums[i] == expectedNums[i]; 
    }

If all assertions pass, then your solution will be accepted.

Example 1:
Input: nums = [1,1,1,2,2,3] 
Output: 5, nums = [1,1,2,2,3,_] 

Example 2:
Input: nums = [0,0,1,1,1,1,2,3,3] 
Output: 7, nums = [0,0,1,1,2,3,3,_,_] 

Constraints:
1 <= nums.length <= 3 * 10^4
-10^4 <= nums[i] <= 10^4
nums is sorted in non-decreasing order.
*/

#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    if (nums.size() <= 2) return nums.size();  // If array has 2 or fewer elements, return its size.

    int index = 2;  // Start from the 3rd element (index 2), as first two elements are allowed.

    for (int i = 2; i < nums.size(); i++) {
        if (nums[i] != nums[index - 2]) {  // Allow at most two occurrences of any element.
            nums[index] = nums[i];
            index++;
        }
    }

    return index;  // 'index' represents the number of unique elements (k).
}

// Test the function
int main() {
    vector<int> nums = {0, 0, 1, 1, 1, 1, 2, 3, 3};
    
    int k = removeDuplicates(nums);

    cout << "Output: " << k << ", nums = [";
    for (int i = 0; i < k; i++) {
        cout << nums[i];
        if (i < k - 1) cout << ", ";
    }
    cout << ", _]\n";  // Underscore represents unimportant elements

    return 0;
}
