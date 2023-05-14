/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/
 *
 * algorithms
 * Medium (63.98%)
 * Likes:    10994
 * Dislikes: 2529
 * Total Accepted:    1.4M
 * Total Submissions: 2.2M
 * Testcase Example:  '[7,1,5,3,6,4]'
 *
 * You are given an integer array prices where prices[i] is the price of a
 * given stock on the i^th day.
 *
 * On each day, you may decide to buy and/or sell the stock. You can only hold
 * at most one share of the stock at any time. However, you can buy it then
 * immediately sell it on the same day.
 *
 * Find and return the maximum profit you can achieve.
 *
 *
 * Example 1:
 *
 *
 * Input: prices = [7,1,5,3,6,4]
 * Output: 7
 * Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit
 * = 5-1 = 4.
 * Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 =
 * 3.
 * Total profit is 4 + 3 = 7.
 *
 *
 * Example 2:
 *
 *
 * Input: prices = [1,2,3,4,5]
 * Output: 4
 * Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit
 * = 5-1 = 4.
 * Total profit is 4.
 *
 *
 * Example 3:
 *
 *
 * Input: prices = [7,6,4,3,1]
 * Output: 0
 * Explanation: There is no way to make a positive profit, so we never buy the
 * stock to achieve the maximum profit of 0.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= prices.length <= 3 * 10^4
 * 0 <= prices[i] <= 10^4
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int helper(vector<int> &p, int i, int flag, vector<vector<int>> &dp)
    {
        if (i == p.size())
            return 0;

        if (dp[i][flag] != -1)
            return dp[i][flag];

        if (flag == 1)
        {
            int x = -p[i] + helper(p, i + 1, 0, dp);
            int y = helper(p, i + 1, 1, dp);
            return dp[i][flag] = max(x, y);
        }
        else if (flag == 0)
        {
            int x = p[i] + helper(p, i + 1, 1, dp);
            int y = helper(p, i + 1, 0, dp);
            return dp[i][flag] = max(x, y);
        }
        return dp[i][flag];
    }
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        return helper(prices, 0, 1, dp);
    }
};
// @lc code=end
