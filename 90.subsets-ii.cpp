/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 *
 * https://leetcode.com/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (55.96%)
 * Likes:    7963
 * Dislikes: 227
 * Total Accepted:    694.1K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,2,2]'
 *
 * Given an integer array nums that may contain duplicates, return all possible
 * subsets (the power set).
 *
 * The solution set must not contain duplicate subsets. Return the solution in
 * any order.
 *
 *
 * Example 1:
 * Input: nums = [1,2,2]
 * Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
 * Example 2:
 * Input: nums = [0]
 * Output: [[],[0]]
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10
 * -10 <= nums[i] <= 10
 *
 *
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        int n = nums.size();
        set<vector<int>> ans;
        for (int i = 0; i < (1 << n); i++)
        {
            vector<int> tmp;
            for (int j = 0; j < n; j++)
            {
                if (i & (1 << j))
                    tmp.push_back(nums[j]);
            }
            sort(tmp.begin(),tmp.end());
            ans.insert(tmp);
        }
        return vector(ans.begin(), ans.end());
    }
};
static bool _foo = ios::sync_with_stdio(false);
static ostream *_bar = cin.tie(NULL);
// @lc code=end
