/*
 * @lc app=leetcode id=1020 lang=cpp
 *
 * [1020] Number of Enclaves
 *
 * https://leetcode.com/problems/number-of-enclaves/description/
 *
 * algorithms
 * Medium (68.73%)
 * Likes:    3340
 * Dislikes: 64
 * Total Accepted:    160.1K
 * Total Submissions: 233K
 * Testcase Example:  '[[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]'
 *
 * You are given an m x n binary matrix grid, where 0 represents a sea cell and
 * 1 represents a land cell.
 *
 * A move consists of walking from one land cell to another adjacent
 * (4-directionally) land cell or walking off the boundary of the grid.
 *
 * Return the number of land cells in grid for which we cannot walk off the
 * boundary of the grid in any number of moves.
 *
 *
 * Example 1:
 *
 *
 * Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
 * Output: 3
 * Explanation: There are three 1s that are enclosed by 0s, and one 1 that is
 * not enclosed because its on the boundary.
 *
 *
 * Example 2:
 *
 *
 * Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
 * Output: 0
 * Explanation: All 1s are either on the boundary or can reach the
 * boundary.
 *
 *
 *
 * Constraints:
 *
 *
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 500
 * grid[i][j] is either 0 or 1.
 *
 *
 */

// @lc code=start
class Solution
{
public:
    void dfs(int i, int j, vector<vector<int>> &grid)
    {
        grid[i][j] = 0;
        int dr[] = {0,-1,0,1};
        int dc[] = {-1,0,1,0};
        for (int x = 0; x < 4; x++)
        {
             int ni = i + dr[x];
            int nj = j + dc[x];
            if (ni < 0 || nj < 0 || ni == grid.size() || nj == grid[0].size() || grid[ni][nj] == 0)
                continue;
            if(grid[ni][nj]==1) dfs(ni, nj, grid);
        }
    }
    int numEnclaves(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
                {   
                    if(grid[i][j]==1)
                    dfs(i, j, grid);
                }
            }
        }
        int ct = 0;
        for (auto x : grid)
            for (auto xx : x)
                if (xx == 1)
                    ct++;
        return ct;
    }
};
// @lc code=end
