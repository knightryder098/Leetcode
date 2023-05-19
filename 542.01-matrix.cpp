/*
 * @lc app=leetcode id=542 lang=cpp
 *
 * [542] 01 Matrix
 *
 * https://leetcode.com/problems/01-matrix/description/
 *
 * algorithms
 * Medium (44.93%)
 * Likes:    7072
 * Dislikes: 333
 * Total Accepted:    382.6K
 * Total Submissions: 851.1K
 * Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
 *
 * Given an m x n binary matrix mat, return the distance of the nearest 0 for
 * each cell.
 *
 * The distance between two adjacent cells is 1.
 *
 *
 * Example 1:
 *
 *
 * Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
 * Output: [[0,0,0],[0,1,0],[0,0,0]]
 *
 *
 * Example 2:
 *
 *
 * Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
 * Output: [[0,0,0],[0,1,0],[1,2,1]]
 *
 *
 *
 * Constraints:
 *
 *
 * m == mat.length
 * n == mat[i].length
 * 1 <= m, n <= 10^4
 * 1 <= m * n <= 10^4
 * mat[i][j] is either 0 or 1.
 * There is at least one 0 in mat.
 *
 *
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        vector<vector<int>> visited(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> lola;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 0)
                {
                    lola.push({{i, j}, 0});
                    visited[i][j] = 1;
                }
            }
        }

        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, -1, 0, 1};
        while (!lola.empty())
        {
            int i = lola.front().first.first;
            int j = lola.front().first.second;
            int d = lola.front().second;
            lola.pop();
            ans[i][j] = d;
            for (int x = 0; x < 4; x++)
            {
                int ni = i + dr[x];
                int nj = j + dc[x];

                if (ni < 0 || ni == n || nj < 0 || nj == m || visited[ni][nj] == 1)
                    continue;
                lola.push({{ni, nj}, d + 1});
                visited[ni][nj] = 1;
            }
        }
        return ans;
    }
};
// @lc code=end
