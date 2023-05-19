/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 *
 * https://leetcode.com/problems/rotting-oranges/description/
 *
 * algorithms
 * Medium (53.05%)
 * Likes:    10388
 * Dislikes: 346
 * Total Accepted:    601.6K
 * Total Submissions: 1.1M
 * Testcase Example:  '[[2,1,1],[1,1,0],[0,1,1]]'
 *
 * You are given an m x n grid where each cell can have one of three
 * values:
 *
 *
 * 0 representing an empty cell,
 * 1 representing a fresh orange, or
 * 2 representing a rotten orange.
 *
 *
 * Every minute, any fresh orange that is 4-directionally adjacent to a rotten
 * orange becomes rotten.
 *
 * Return the minimum number of minutes that must elapse until no cell has a
 * fresh orange. If this is impossible, return -1.
 *
 *
 * Example 1:
 *
 *
 * Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
 * Output: 4
 *
 *
 * Example 2:
 *
 *
 * Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
 * Output: -1
 * Explanation: The orange in the bottom left corner (row 2, column 0) is never
 * rotten, because rotting only happens 4-directionally.
 *
 *
 * Example 3:
 *
 *
 * Input: grid = [[0,2]]
 * Output: 0
 * Explanation: Since there are already no fresh oranges at minute 0, the
 * answer is just 0.
 *
 *
 *
 * Constraints:
 *
 *
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 10
 * grid[i][j] is 0, 1, or 2.
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        queue<pair<int, int>> lola;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                    lola.push({i, j});
            }
        }
        vector<int> dr = {0, -1, 0, 1};
        vector<int> dc = {-1,0,1,0};
        while (!lola.empty())
        {    
            int sz = lola.size();
            bool flag=false;
            for (int i = 0; i < sz; i++)
            {
                int row = lola.front().first;
                int col = lola.front().second;
                lola.pop();
                for (int x = 0; x < 4; x++)
                {
                    int nr = row + dr[x];
                    int nc = col + dc[x];
                    if (nr < 0 || nr >= n || nc < 0 || nc >= m || grid[nr][nc] == 0 || grid[nr][nc] == 2)continue;
                    
                    grid[nr][nc]=2;
                    flag=true;
                    lola.push({nr, nc});
                }
            }
            if(flag)ans++;
           
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }
        return ans;
    }
};
// @lc code=end
