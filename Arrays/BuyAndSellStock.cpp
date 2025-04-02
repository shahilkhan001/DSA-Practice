/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Example 1:
Input: prices = [7,1,5,3,6,4] 
Output: 5 
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.

Example 2:
Input: prices = [7,6,4,3,1] 
Output: 0 
Explanation: In this case, no transactions are done and the max profit = 0.

Constraints:
1 <= prices.length <= 10^5
0 <= prices[i] <= 10^4
*/

#include <iostream>
#include <vector>
#include <climits>  // For INT_MAX

using namespace std;

int maxProfit(vector<int>& prices) {
    int minPrice = INT_MAX;  // Track the minimum price encountered
    int maxProfit = 0;       // Track the maximum profit

    for (int price : prices) {
        minPrice = min(minPrice, price);  // Update minimum price
        maxProfit = max(maxProfit, price - minPrice);  // Update max profit
    }
    
    return maxProfit;
}

// Function to test maxProfit
int main() {
    vector<int> prices = {7,1,5,3,6,4};

    cout << "Maximum Profit: " << maxProfit(prices) << endl;  // Expected Output: 5

    return 0;
}
