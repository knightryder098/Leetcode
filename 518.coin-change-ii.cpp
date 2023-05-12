/*
 * @lc app=leetcode id=518 lang=cpp
 *
 * [518] Coin Change II
 *
 * https://leetcode.com/problems/coin-change-ii/description/
 *
 * algorithms
 * Medium (60.69%)
 * Likes:    7168
 * Dislikes: 130
 * Total Accepted:    410.7K
 * Total Submissions: 676.3K
 * Testcase Example:  '5\n[1,2,5]'
 *
 * You are given an integer array coins representing coins of different
 * denominations and an integer amount representing a total amount of money.
 *
 * Return the number of combinations that make up that amount. If that amount
 * of money cannot be made up by any combination of the coins, return 0.
 *
 * You may assume that you have an infinite number of each kind of coin.
 *
 * The answer is guaranteed to fit into a signed 32-bit integer.
 *
 *
 * Example 1:
 *
 *
 * Input: amount = 5, coins = [1,2,5]
 * Output: 4
 * Explanation: there are four ways to make up the amount:
 * 5=5
 * 5=2+2+1
 * 5=2+1+1+1
 * 5=1+1+1+1+1
 *
 *
 * Example 2:
 *
 *
 * Input: amount = 3, coins = [2]
 * Output: 0
 * Explanation: the amount of 3 cannot be made up just with coins of 2.
 *
 *
 * Example 3:
 *
 *
 * Input: amount = 10, coins = [10]
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= coins.length <= 300
 * 1 <= coins[i] <= 5000
 * All the values of coins are unique.
 * 0 <= amount <= 5000
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int helper(int i, vector<int> &coins, int a,vector<vector<int>>&dp)
    {
        if (i == 0)
        {
            if (a % coins[0] == 0)
                return 1;
            else
                return 0;
        }

        if(dp[i][a]!=-1)return dp[i][a];

        int nottake = helper(i - 1, coins, a,dp);
        int take = 0;
        if (coins[i] <= a)
            take = helper(i, coins, a - coins[i],dp);
        return dp[i][a]=take + nottake;
    }
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return helper(n - 1, coins, amount,dp);
    }
};
// @lc code=end
