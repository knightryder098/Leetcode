/*
 * @lc app=leetcode id=2466 lang=cpp
 *
 * [2466] Count Ways To Build Good Strings
 *
 * https://leetcode.com/problems/count-ways-to-build-good-strings/description/
 *
 * algorithms
 * Medium (42.04%)
 * Likes:    576
 * Dislikes: 56
 * Total Accepted:    19.5K
 * Total Submissions: 39.7K
 * Testcase Example:  '3\n3\n1\n1'
 *
 * Given the integers zero, one, low, and high, we can construct a string by
 * starting with an empty string, and then at each step perform either of the
 * following:
 *
 *
 * Append the character '0' zero times.
 * Append the character '1' one times.
 *
 *
 * This can be performed any number of times.
 *
 * A good string is a string constructed by the above process having a length
 * between low and high (inclusive).
 *
 * Return the number of different good strings that can be constructed
 * satisfying these properties. Since the answer can be large, return it modulo
 * 10^9 + 7.
 *
 *
 * Example 1:
 *
 *
 * Input: low = 3, high = 3, zero = 1, one = 1
 * Output: 8
 * Explanation:
 * One possible valid good string is "011".
 * It can be constructed as follows: "" -> "0" -> "01" -> "011".
 * All binary strings from "000" to "111" are good strings in this example.
 *
 *
 * Example 2:
 *
 *
 * Input: low = 2, high = 3, zero = 1, one = 2
 * Output: 5
 * Explanation: The good strings are "00", "11", "000", "110", and "011".
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= low <= high <= 10^5
 * 1 <= zero, one <= low
 *
 *
 */

// @lc code=start
#define mod 1000000007
class Solution
{
public:
    int helper(int zero, int one, int len,vector<int>&dp)
    {
        if(len==0)return 1;

        if(dp[len]!=-1)return dp[len];

        long long int cnt = 0;
        if (len >= zero)
            cnt += helper(zero, one, len - zero,dp);
        if (len >= one)
            cnt += helper(zero, one, len - one,dp);

        return dp[len]=cnt%mod;
    }
    int countGoodStrings(int low, int high, int zero, int one)
    {
        long ans = 0;
        vector<int>dp(high+1,-1);
        for (int i = low; i <= high; i++)
        {
            ans=(ans+ helper(zero, one, i,dp))%mod;
        }
        return ans;
    }
};
// @lc code=end
