/*
 * @lc app=leetcode id=1039 lang=cpp
 *
 * [1039] Minimum Score Triangulation of Polygon
 *
 * https://leetcode.com/problems/minimum-score-triangulation-of-polygon/description/
 *
 * algorithms
 * Medium (55.71%)
 * Likes:    1492
 * Dislikes: 146
 * Total Accepted:    34.5K
 * Total Submissions: 61.8K
 * Testcase Example:  '[1,2,3]'
 *
 * You have a convex n-sided polygon where each vertex has an integer value.
 * You are given an integer array values where values[i] is the value of the
 * i^th vertex (i.e., clockwise order).
 *
 * You will triangulate the polygon into n - 2 triangles. For each triangle,
 * the value of that triangle is the product of the values of its vertices, and
 * the total score of the triangulation is the sum of these values over all n -
 * 2 triangles in the triangulation.
 *
 * Return the smallest possible total score that you can achieve with some
 * triangulation of the polygon.
 *
 *
 * Example 1:
 *
 *
 * Input: values = [1,2,3]
 * Output: 6
 * Explanation: The polygon is already triangulated, and the score of the only
 * triangle is 6.
 *
 *
 * Example 2:
 *
 *
 * Input: values = [3,7,4,5]
 * Output: 144
 * Explanation: There are two triangulations, with possible scores: 3*7*5 +
 * 4*5*7 = 245, or 3*4*5 + 3*4*7 = 144.
 * The minimum score is 144.
 *
 *
 * Example 3:
 *
 *
 * Input: values = [1,3,1,4,1,5]
 * Output: 13
 * Explanation: The minimum score triangulation has score 1*1*3 + 1*1*4 + 1*1*5
 * + 1*1*1 = 13.
 *
 *
 *
 * Constraints:
 *
 *
 * n == values.length
 * 3 <= n <= 50
 * 1 <= values[i] <= 100
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int helper(int i, int j, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (i >= j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];
        int mini = 1e9;
        for (int k = i; k < j; k++)
        {
            int tmp = nums[i - 1] * nums[k] * nums[j] + helper(i, k, nums, dp) + helper(k + 1, j, nums, dp);
            mini = min(mini, tmp);
        }
        return dp[i][j] = mini;
    }
    int minScoreTriangulation(vector<int> &values)
    {
        int n = values.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return helper(1, n - 1, values, dp);
    }
};
// @lc code=end
