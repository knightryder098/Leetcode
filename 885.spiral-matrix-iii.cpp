/*
 * @lc app=leetcode id=885 lang=cpp
 *
 * [885] Spiral Matrix III
 *
 * https://leetcode.com/problems/spiral-matrix-iii/description/
 *
 * algorithms
 * Medium (73.65%)
 * Likes:    790
 * Dislikes: 770
 * Total Accepted:    42.7K
 * Total Submissions: 58K
 * Testcase Example:  '1\n4\n0\n0'
 *
 * You start at the cell (rStart, cStart) of an rows x cols grid facing east.
 * The northwest corner is at the first row and column in the grid, and the
 * southeast corner is at the last row and column.
 *
 * You will walk in a clockwise spiral shape to visit every position in this
 * grid. Whenever you move outside the grid's boundary, we continue our walk
 * outside the grid (but may return to the grid boundary later.). Eventually,
 * we reach all rows * cols spaces of the grid.
 *
 * Return an array of coordinates representing the positions of the grid in the
 * order you visited them.
 *
 *
 * Example 1:
 *
 *
 * Input: rows = 1, cols = 4, rStart = 0, cStart = 0
 * Output: [[0,0],[0,1],[0,2],[0,3]]
 *
 *
 * Example 2:
 *
 *
 * Input: rows = 5, cols = 6, rStart = 1, cStart = 4
 * Output:
 * [[1,4],[1,5],[2,5],[2,4],[2,3],[1,3],[0,3],[0,4],[0,5],[3,5],[3,4],[3,3],[3,2],[2,2],[1,2],[0,2],[4,5],[4,4],[4,3],[4,2],[4,1],[3,1],[2,1],[1,1],[0,1],[4,0],[3,0],[2,0],[1,0],[0,0]]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= rows, cols <= 100
 * 0 <= rStart < rows
 * 0 <= cStart < cols
 *
 *
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> spiralMatrixIII(int n, int m, int i, int j)
    {
        vector<vector<int>> ans;
        int dr[] = {0, 1, 0, -1};
        int dc[] = {1, 0, -1, 0};
        int step = 1, dir = 0;
        while (ans.size() < n * m)
        {
            for (int x = 0; x < step; x++)
            {
                if (i >= 0 and i < n and j >= 0 and j < m)
                    ans.push_back({i, j});
                i += dr[dir];
                j += dc[dir];
            }
            dir = (dir + 1) % 4;
            for (int x = 0; x < step; x++)
            {
                if (i >= 0 and i < n and j >= 0 and j < m)
                    ans.push_back({i, j});
                i += dr[dir];
                j += dc[dir];
            }
            dir = (dir + 1) % 4;
            step++;
        }
        return ans;
    }
};
// @lc code=end
