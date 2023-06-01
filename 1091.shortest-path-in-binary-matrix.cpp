/*
 * @lc app=leetcode id=1091 lang=cpp
 *
 * [1091] Shortest Path in Binary Matrix
 *
 * https://leetcode.com/problems/shortest-path-in-binary-matrix/description/
 *
 * algorithms
 * Medium (44.79%)
 * Likes:    4700
 * Dislikes: 181
 * Total Accepted:    305.5K
 * Total Submissions: 681.8K
 * Testcase Example:  '[[0,1],[1,0]]'
 *
 * Given an n x n binary matrix grid, return the length of the shortest clear
 * path in the matrix. If there is no clear path, return -1.
 *
 * A clear path in a binary matrix is a path from the top-left cell (i.e., (0,
 * 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:
 *
 *
 * All the visited cells of the path are 0.
 * All the adjacent cells of the path are 8-directionally connected (i.e., they
 * are different and they share an edge or a corner).
 *
 *
 * The length of a clear path is the number of visited cells of this path.
 *
 *
 * Example 1:
 *
 *
 * Input: grid = [[0,1],[1,0]]
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
 * Output: 4
 *
 *
 * Example 3:
 *
 *
 * Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
 * Output: -1
 *
 *
 *
 * Constraints:
 *
 *
 * n == grid.length
 * n == grid[i].length
 * 1 <= n <= 100
 * grid[i][j] is 0 or 1
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> distance(n + 1, vector<int>(m + 1, INT_MAX));
        priority_queue<pair<int, pair<int, int>>> pq;
        int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1, 0, 0};
        int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        if (grid[0][0] == 0){

            pq.push({-1, {0, 0}});
            distance[0][0]=1;
        }
        
        while (pq.size())
        {
            int dis = -1 * pq.top().first;
            auto parent = pq.top().second;
            pq.pop();
            for (int x = 0; x < 8; x++)
            {
                int ni = parent.first + dr[x];
                int nj = parent.second + dc[x];
                if (ni >= 0 and ni < grid.size() and nj >= 0 and nj < grid[0].size() and grid[ni][nj] == 0)
                {
                    if (dis + 1 < distance[ni][nj])
                    {
                        distance[ni][nj] = dis + 1;
                        pq.push({-distance[ni][nj], {ni, nj}});
                    }
                }
            }
        }
        if (distance[n - 1][m - 1] == INT_MAX)
            return -1;
        return distance[n - 1][m - 1];
    }
};
// @lc code=end
