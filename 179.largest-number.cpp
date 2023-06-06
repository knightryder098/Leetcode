/*
 * @lc app=leetcode id=179 lang=cpp
 *
 * [179] Largest Number
 *
 * https://leetcode.com/problems/largest-number/description/
 *
 * algorithms
 * Medium (34.70%)
 * Likes:    6986
 * Dislikes: 569
 * Total Accepted:    397.6K
 * Total Submissions: 1.1M
 * Testcase Example:  '[10,2]'
 *
 * Given a list of non-negative integers nums, arrange them such that they form
 * the largest number and return it.
 *
 * Since the result may be very large, so you need to return a string instead
 * of an integer.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [10,2]
 * Output: "210"
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [3,30,34,5,9]
 * Output: "9534330"
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 100
 * 0 <= nums[i] <= 10^9
 *
 *
 */

// @lc code=start
class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        vector<string> tmp;
        for (auto x : nums)
            tmp.push_back(to_string(x));
        sort(begin(tmp), end(tmp), [&](auto &a, auto &b)
             { return a + b > b + a; });
        string s = "";
        for (auto x : tmp)
            s += x;
        while (s[0] == '0' and s.size() > 1)
            s.erase(s.begin());
        return s;
    }
};
// @lc code=end
