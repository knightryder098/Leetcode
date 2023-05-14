/*
 * @lc app=leetcode id=123 lang=cpp
 *
 * [123] Best Time to Buy and Sell Stock III
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/
 *
 * algorithms
 * Hard (45.61%)
 * Likes:    8099
 * Dislikes: 157
 * Total Accepted:    477.7K
 * Total Submissions: 1M
 * Testcase Example:  '[3,3,5,0,0,3,1,4]'
 *
 * You are given an array prices where prices[i] is the price of a given stock
 * on the i^th day.
 *
 * Find the maximum profit you can achieve. You may complete at most two
 * transactions.
 *
 * Note: You may not engage in multiple transactions simultaneously (i.e., you
 * must sell the stock before you buy again).
 *
 *
 * Example 1:
 *
 *
 * Input: prices = [3,3,5,0,0,3,1,4]
 * Output: 6
 * Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit
 * = 3-0 = 3.
 * Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 =
 * 3.
 *
 * Example 2:
 *
 *
 * Input: prices = [1,2,3,4,5]
 * Output: 4
 * Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit
 * = 5-1 = 4.
 * Note that you cannot buy on day 1, buy on day 2 and sell them later, as you
 * are engaging multiple transactions at the same time. You must sell before
 * buying again.
 *
 *
 * Example 3:
 *
 *
 * Input: prices = [7,6,4,3,1]
 * Output: 0
 * Explanation: In this case, no transaction is done, i.e. max profit = 0.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= prices.length <= 10^5
 * 0 <= prices[i] <= 10^5
 *
 *
 */

// @lc code=start
class Solution
{
public:
     int helper(vector<int> &p, int i, int flag, int times, vector<vector<vector<int>>> &dp)
    {
        if (i == p.size()|| times==2)
            return 0;

        if (dp[i][flag][times] != -1)
            return dp[i][flag][times];

        if (flag == 1)
        {
            int buynow = -p[i] + helper(p, i + 1, 0, times, dp);
            int buylater = helper(p, i + 1, 1, times, dp);
            return dp[i][flag][times]=max(buynow, buylater);
        }
        else
        {   
            int sellnow=0,selllater=0;
           
            sellnow = p[i] + helper(p, i + 1, 1, times+1, dp);
            selllater = helper(p, i + 1, 0, times, dp);
           
            return dp[i][flag][times]=max(selllater, sellnow);
              
            
        }
        // return dp[i][flag];
    }
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3,-1)));
        return helper(prices, 0, 1, 0, dp);
    }
};
// @lc code=end
