/*
 * @lc app=leetcode id=1799 lang=cpp
 *
 * [1799] Maximize Score After N Operations
 *
 * https://leetcode.com/problems/maximize-score-after-n-operations/description/
 *
 * algorithms
 * Hard (46.38%)
 * Likes:    902
 * Dislikes: 70
 * Total Accepted:    28.4K
 * Total Submissions: 53.9K
 * Testcase Example:  '[1,2]'
 *
 * You are given nums, an array of positive integers of size 2 * n. You must
 * perform n operations on this array.
 * 
 * In the i^th operation (1-indexed), you will:
 * 
 * 
 * Choose two elements, x and y.
 * Receive a score of i * gcd(x, y).
 * Remove x and y from nums.
 * 
 * 
 * Return the maximum score you can receive after performing n operations.
 * 
 * The function gcd(x, y) is the greatest common divisor of x and y.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2]
 * Output: 1
 * Explanation: The optimal choice of operations is:
 * (1 * gcd(1, 2)) = 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [3,4,6,8]
 * Output: 11
 * Explanation: The optimal choice of operations is:
 * (1 * gcd(3, 6)) + (2 * gcd(4, 8)) = 3 + 8 = 11
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [1,2,3,4,5,6]
 * Output: 14
 * Explanation: The optimal choice of operations is:
 * (1 * gcd(1, 5)) + (2 * gcd(2, 4)) + (3 * gcd(3, 6)) = 1 + 4 + 9 = 14
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 7
 * nums.length == 2 * n
 * 1 <= nums[i] <= 10^6
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int helper(vector<int>&nums,int mul,int grp,vector<int>&dp){

        if(mul>(nums.size()/2))return 0;

        if(dp[grp]!=-1)return dp[grp];

        for(int i=0;i<nums.size();i++){
            if((grp&(1<<i)))continue;
            for(int j=i+1;j<nums.size();j++){
                if((grp&(1<<j)))continue;
                int xxx=(grp|(1<<i)|(1<<j));
                int tmp=__gcd(nums[i],nums[j])*mul+helper(nums,mul+1,xxx,dp);
                dp[grp]=max(dp[grp],tmp);
            }
        }
    return dp[grp];
    }
    int maxScore(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp((1<<n),-1);
        return helper(nums,1,0,dp);
    }
};
// @lc code=end

