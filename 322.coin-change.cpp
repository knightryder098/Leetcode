/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 *
 * https://leetcode.com/problems/coin-change/description/
 *
 * algorithms
 * Medium (42.16%)
 * Likes:    16037
 * Dislikes: 364
 * Total Accepted:    1.4M
 * Total Submissions: 3.3M
 * Testcase Example:  '[1,2,5]\n11'
 *
 * You are given an integer array coins representing coins of different
 * denominations and an integer amount representing a total amount of money.
 *
 * Return the fewest number of coins that you need to make up that amount. If
 * that amount of money cannot be made up by any combination of the coins,
 * return -1.
 *
 * You may assume that you have an infinite number of each kind of coin.
 *
 *
 * Example 1:
 *
 *
 * Input: coins = [1,2,5], amount = 11
 * Output: 3
 * Explanation: 11 = 5 + 5 + 1
 *
 *
 * Example 2:
 *
 *
 * Input: coins = [2], amount = 3
 * Output: -1
 *
 *
 * Example 3:
 *
 *
 * Input: coins = [1], amount = 0
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= coins.length <= 12
 * 1 <= coins[i] <= 2^31 - 1
 * 0 <= amount <= 10^4
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int helper(vector<int> &coins, int a,vector<int>&dp)
    {
        if (a == 0)
            return 0;
        if (a < 0)
            return -1;

        if(dp[a]!=-2)return dp[a];
        int ans = INT_MAX;
        for (auto c : coins)
        {
            int res = helper(coins, a - c,dp);
            if (res >= 0 and res < ans)
            {
                ans = res + 1;
            }
        }
        return dp[a]=(ans==INT_MAX)?-1:ans;
    }
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<int>dp(amount+1,-2);
        return helper(coins, amount,dp);
    }
};
// @lc code=end
