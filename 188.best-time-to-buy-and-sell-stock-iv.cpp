/*
 * @lc app=leetcode id=188 lang=cpp
 *
 * [188] Best Time to Buy and Sell Stock IV
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/
 *
 * algorithms
 * Hard (39.11%)
 * Likes:    6368
 * Dislikes: 197
 * Total Accepted:    357.6K
 * Total Submissions: 912.8K
 * Testcase Example:  '2\n[2,4,1]'
 *
 * You are given an integer array prices where prices[i] is the price of a
 * given stock on the i^th day, and an integer k.
 *
 * Find the maximum profit you can achieve. You may complete at most k
 * transactions: i.e. you may buy at most k times and sell at most k times.
 *
 * Note: You may not engage in multiple transactions simultaneously (i.e., you
 * must sell the stock before you buy again).
 *
 *
 * Example 1:
 *
 *
 * Input: k = 2, prices = [2,4,1]
 * Output: 2
 * Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit
 * = 4-2 = 2.
 *
 *
 * Example 2:
 *
 *
 * Input: k = 2, prices = [3,2,6,5,0,3]
 * Output: 7
 * Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit
 * = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3),
 * profit = 3-0 = 3.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= k <= 100
 * 1 <= prices.length <= 1000
 * 0 <= prices[i] <= 1000
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int helper(vector<int> &p,int i, int flag, int k, vector<vector<vector<int>>> &dp)
    {
        if (i == p.size() || k == 0)
            return 0;
        if (dp[i][flag][k] != -1)
            return dp[i][flag][k];

        if (flag == 1)
        {
            int buynow = -p[i] + helper(p, i + 1, 0, k, dp);
            int buylatter = helper(p, i + 1, 1, k, dp);
            return dp[i][flag][k] = max(buylatter, buynow);
        }
        else
        {
            int sellnow = p[i] + helper(p, i + 1, 1, k - 1, dp);
            int selllater = helper(p, i + 1, 0, k, dp);
            return dp[i][flag][k] = max(selllater, sellnow);
        }
    }
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return helper(prices, 0, 1, k, dp);
    }
};
// @lc code=end
