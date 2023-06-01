/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 *
 * https://leetcode.com/problems/combinations/description/
 *
 * algorithms
 * Medium (67.17%)
 * Likes:    6072
 * Dislikes: 189
 * Total Accepted:    669.9K
 * Total Submissions: 996.2K
 * Testcase Example:  '4\n2'
 *
 * Given two integers n and k, return all possible combinations of k numbers
 * chosen from the range [1, n].
 *
 * You may return the answer in any order.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 4, k = 2
 * Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
 * Explanation: There are 4 choose 2 = 6 total combinations.
 * Note that combinations are unordered, i.e., [1,2] and [2,1] are considered
 * to be the same combination.
 *
 *
 * Example 2:
 *
 *
 * Input: n = 1, k = 1
 * Output: [[1]]
 * Explanation: There is 1 choose 1 = 1 total combination.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 20
 * 1 <= k <= n
 *
 *
 */

// @lc code=start
class Solution
{
public:
    void helper(int start, int end, int k, vector<vector<int>> &ans, vector<int> &curr)
    {
        if (curr.size() == k)
        {
            ans.push_back(curr);
            return;
        }
        if (start > end)
            return;
        curr.push_back(start);
        helper(start + 1, end, k, ans, curr);
        curr.pop_back();
        helper(start + 1, end, k, ans, curr);
    }
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> ans;
        vector<int> curr;
        helper(1, n, k, ans, curr);
        return ans;
    }
};
// @lc code=end
