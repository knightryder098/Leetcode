/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 *
 * https://leetcode.com/problems/house-robber/description/
 *
 * algorithms
 * Medium (49.48%)
 * Likes:    17620
 * Dislikes: 334
 * Total Accepted:    1.6M
 * Total Submissions: 3.2M
 * Testcase Example:  '[1,2,3,1]'
 *
 * You are a professional robber planning to rob houses along a street. Each
 * house has a certain amount of money stashed, the only constraint stopping
 * you from robbing each of them is that adjacent houses have security systems
 * connected and it will automatically contact the police if two adjacent
 * houses were broken into on the same night.
 *
 * Given an integer array nums representing the amount of money of each house,
 * return the maximum amount of money you can rob tonight without alerting the
 * police.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,3,1]
 * Output: 4
 * Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
 * Total amount you can rob = 1 + 3 = 4.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [2,7,9,3,1]
 * Output: 12
 * Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house
 * 5 (money = 1).
 * Total amount you can rob = 2 + 9 + 1 = 12.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 100
 * 0 <= nums[i] <= 400
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int helper(int i, vector<int> &num,vector<int>&dp)
    {
        int n = num.size();
        if (i == n - 1)
            return num[i];
        if (i >= n)
            return 0;

        if(dp[i]!=-1)return dp[i];
        int nottake = helper(i + 1, num,dp);
        int take = num[i] + helper(i + 2, num,dp);

        return dp[i]=max(take, nottake);
    }
    int rob(vector<int> &nums)
    {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return helper(0, nums,dp);
    }
};
// @lc code=end
