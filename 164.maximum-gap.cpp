/*
 * @lc app=leetcode id=164 lang=cpp
 *
 * [164] Maximum Gap
 *
 * https://leetcode.com/problems/maximum-gap/description/
 *
 * algorithms
 * Hard (43.52%)
 * Likes:    2808
 * Dislikes: 333
 * Total Accepted:    169.2K
 * Total Submissions: 388.3K
 * Testcase Example:  '[3,6,9,1]'
 *
 * Given an integer array nums, return the maximum difference between two
 * successive elements in its sorted form. If the array contains less than two
 * elements, return 0.
 *
 * You must write an algorithm that runs in linear time and uses linear extra
 * space.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [3,6,9,1]
 * Output: 3
 * Explanation: The sorted form of the array is [1,3,6,9], either (3,6) or
 * (6,9) has the maximum difference 3.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [10]
 * Output: 0
 * Explanation: The array contains less than 2 elements, therefore return
 * 0.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * 0 <= nums[i] <= 10^9
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int maximumGap(vector<int> &nums)
    {
        // perform radix sort
        if (nums.size() <= 1)
            return 0;
        int maxi = *max_element(begin(nums), end(nums));
        int exp = 1;
        while (maxi / exp > 0)
        {
            vector<int> buckets[10];
            for (auto x : nums)
            {
                int digit = (x / exp) % 10;
                buckets[digit].push_back(x);
            }
            nums.clear();
            for (auto x : buckets)
            {
                nums.insert(nums.end(), x.begin(), x.end());
            }
            exp *= 10;
        }

        int ans = -1;
        for (int i = 1; i < nums.size(); i++)
        {
            ans = max(ans, nums[i] - nums[i - 1]);
        }
        return ans;
    }
};
// @lc code=end
