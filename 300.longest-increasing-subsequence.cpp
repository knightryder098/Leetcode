/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 *
 * https://leetcode.com/problems/longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (52.26%)
 * Likes:    17171
 * Dislikes: 324
 * Total Accepted:    1.2M
 * Total Submissions: 2.3M
 * Testcase Example:  '[10,9,2,5,3,7,101,18]'
 *
 * Given an integer array nums, return the length of the longest strictly
 * increasing subsequence.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [10,9,2,5,3,7,101,18]
 * Output: 4
 * Explanation: The longest increasing subsequence is [2,3,7,101], therefore
 * the length is 4.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [0,1,0,3,2,3]
 * Output: 4
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [7,7,7,7,7,7,7]
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 2500
 * -10^4 <= nums[i] <= 10^4
 *
 *
 *
 * Follow up: Can you come up with an algorithm that runs in O(n log(n)) time
 * complexity?
 *
 */

// @lc code=start
class Solution
{
public:
    int helper(int i, int prev, vector<int> &nums,vector<vector<int>>&dp)
    {
        if(i<0)return 0;

        if(dp[i][prev]!=-1)return dp[i][prev];

        if (prev==nums.size()||nums[i] < nums[prev])
        {
            return dp[i][prev]=max(1+helper(i - 1, i, nums,dp), helper(i - 1, prev, nums,dp));
        }
        else
            return dp[i][prev]=helper(i - 1, prev, nums,dp);
    }
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return helper(n - 1, n, nums,dp);
    }
};
// @lc code=end
