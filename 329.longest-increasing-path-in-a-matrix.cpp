/*
 * @lc app=leetcode id=329 lang=cpp
 *
 * [329] Longest Increasing Path in a Matrix
 *
 * https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/
 *
 * algorithms
 * Hard (52.51%)
 * Likes:    8041
 * Dislikes: 118
 * Total Accepted:    446.6K
 * Total Submissions: 850K
 * Testcase Example:  '[[9,9,4],[6,6,8],[2,1,1]]'
 *
 * Given an m x n integers matrix, return the length of the longest increasing
 * path in matrix.
 *
 * From each cell, you can either move in four directions: left, right, up, or
 * down. You may not move diagonally or move outside the boundary (i.e.,
 * wrap-around is not allowed).
 *
 *
 * Example 1:
 *
 *
 * Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
 * Output: 4
 * Explanation: The longest increasing path is [1, 2, 6, 9].
 *
 *
 * Example 2:
 *
 *
 * Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
 * Output: 4
 * Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally
 * is not allowed.
 *
 *
 * Example 3:
 *
 *
 * Input: matrix = [[1]]
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 200
 * 0 <= matrix[i][j] <= 2^31 - 1
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int helper(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &distance)
    {
        if (distance[i][j])
            return distance[i][j];
        distance[i][j] = 1;
        int dr[] = {0, -1, 0, 1};
        int dc[] = {1, 0, -1, 0};
        for (int x = 0; x < 4; x++)
        {
            int ni = i + dr[x];
            int nj = j + dc[x];
            if (ni < 0 || nj < 0 || ni == matrix.size() || nj == matrix[0].size() || matrix[i][j] >= matrix[ni][nj])
                continue;

            distance[i][j] = max(distance[i][j], 1 + helper(ni, nj, matrix, distance));
        }
        return distance[i][j];
    }
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> distance(n, vector<int>(m, 0));
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                ans = max(ans, helper(i, j, matrix, distance));
            }
        }
        return ans;
    }
};
// @lc code=end
