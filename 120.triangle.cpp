/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 *
 * https://leetcode.com/problems/triangle/description/
 *
 * algorithms
 * Medium (54.58%)
 * Likes:    8048
 * Dislikes: 483
 * Total Accepted:    589.5K
 * Total Submissions: 1.1M
 * Testcase Example:  '[[2],[3,4],[6,5,7],[4,1,8,3]]'
 *
 * Given a triangle array, return the minimum path sum from top to bottom.
 *
 * For each step, you may move to an adjacent number of the row below. More
 * formally, if you are on index i on the current row, you may move to either
 * index i or index i + 1 on the next row.
 *
 *
 * Example 1:
 *
 *
 * Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
 * Output: 11
 * Explanation: The triangle looks like:
 * ⁠  2
 * ⁠ 3 4
 * ⁠6 5 7
 * 4 1 8 3
 * The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined
 * above).
 *
 *
 * Example 2:
 *
 *
 * Input: triangle = [[-10]]
 * Output: -10
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= triangle.length <= 200
 * triangle[0].length == 1
 * triangle[i].length == triangle[i - 1].length + 1
 * -10^4 <= triangle[i][j] <= 10^4
 *
 *
 *
 * Follow up: Could you do this using only O(n) extra space, where n is the
 * total number of rows in the triangle?
 */

// @lc code=start
class Solution
{
public:
    int helper(vector<vector<int>> &t, int i, int j, vector<vector<int>> &dp)
    {
        if (i == t.size() - 1)
            return t[i][j];
        if (dp[i][j] != -1)
            return dp[i][j];
        int left = helper(t, i + 1, j, dp);
        int right = helper(t, i + 1, j + 1, dp);
        return dp[i][j] = min(left, right) + t[i][j];
    }
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        int m = triangle[n - 1].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return helper(triangle, 0, 0, dp);
    }
};

// @lc code=end
