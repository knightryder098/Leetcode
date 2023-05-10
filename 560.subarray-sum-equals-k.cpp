/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 *
 * https://leetcode.com/problems/subarray-sum-equals-k/description/
 *
 * algorithms
 * Medium (43.62%)
 * Likes:    18030
 * Dislikes: 523
 * Total Accepted:    965.5K
 * Total Submissions: 2.2M
 * Testcase Example:  '[1,1,1]\n2'
 *
 * Given an array of integers nums and an integer k, return the total number of
 * subarrays whose sum equals to k.
 *
 * A subarray is a contiguous non-empty sequence of elements within an
 * array.
 *
 *
 * Example 1:
 * Input: nums = [1,1,1], k = 2
 * Output: 2
 * Example 2:
 * Input: nums = [1,2,3], k = 3
 * Output: 2
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 2 * 10^4
 * -1000 <= nums[i] <= 1000
 * -10^7 <= k <= 10^7
 *
 *
 */

// @lc code=start
class Solution
{
public:
    void helper(vector<int> &nums, vector<int> &ds, set<vector<int>> &lola, int n, int k, int sum)
    {
        if (n == 0)
        {
            if (k == sum)
            {
                ds.push_back(0);
                lola.insert(ds);
                return;
            }
            return;
        }

        if (k == sum)
        {
            lola.insert(ds);
            return;
        }

        if (sum <= k)
        {
            ds.push_back(n);
            helper(nums, ds, lola, n - 1, k, sum + nums[n]);
            ds.pop_back();
            helper(nums, ds, lola, n - 1, k, sum);
        }
    }
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        int ans = 0;
        // unordered_map<int,int> mp;
        // int sum=0;
        // mp[0]=1;
        // for(int i=0;i<n;i++){
        //     sum+=nums[i];
        //     if(mp.find(sum-k)!=mp.end()){
        //         ans+=mp[sum-k];
        //     }
        //     mp[sum]++;
        // }
        // return ans;
        vector<int> ds;
        set<vector<int>> lola;
        vector<vector<int>>dp(n,vector<int>(k+1,0));
        helper(nums, ds, lola, n-1, k, nums[n-1]);
        return lola.size();
    }
};
// @lc code=end
