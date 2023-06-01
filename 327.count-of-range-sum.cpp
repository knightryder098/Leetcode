/*
 * @lc app=leetcode id=327 lang=cpp
 *
 * [327] Count of Range Sum
 *
 * https://leetcode.com/problems/count-of-range-sum/description/
 *
 * algorithms
 * Hard (35.77%)
 * Likes:    2042
 * Dislikes: 212
 * Total Accepted:    69K
 * Total Submissions: 192.8K
 * Testcase Example:  '[-2,5,-1]\n-2\n2'
 *
 * Given an integer array nums and two integers lower and upper, return the
 * number of range sums that lie in [lower, upper] inclusive.
 *
 * Range sum S(i, j) is defined as the sum of the elements in nums between
 * indices i and j inclusive, where i <= j.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [-2,5,-1], lower = -2, upper = 2
 * Output: 3
 * Explanation: The three ranges are: [0,0], [2,2], and [0,2] and their
 * respective sums are: -2, -1, 2.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [0], lower = 0, upper = 0
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * -2^31 <= nums[i] <= 2^31 - 1
 * -10^5 <= lower <= upper <= 10^5
 * The answer is guaranteed to fit in a 32-bit integer.
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int helper(vector<long> &num, int lower, int upper, int l, int r)
    {
        if (r - l <= 1)
            return 0;
        int mid = (r + l) / 2;
        int m = mid, n = mid;
        int count = 0;
        count += helper(num, lower, upper, l, mid) + helper(num, lower, upper, mid, r);
        for (int i = l; i < mid; i++)
        {
            while (m < r and num[m] - num[i] < lower)
                m++;
            while (n < r and num[n] - num[i] <= upper)
                n++;
            count += n - m;
        }
        inplace_merge(num.begin() + l, num.begin() + mid, num.begin() + r);
        return count;
    }
    int countRangeSum(vector<int> &nums, int lower, int upper)
    {
        int n = nums.size();
        vector<long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        return helper(prefix, lower, upper, 0, n + 1);
    }
};
// @lc code=end
