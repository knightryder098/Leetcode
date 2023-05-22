/*
 * @lc app=leetcode id=934 lang=cpp
 *
 * [934] Shortest Bridge
 *
 * https://leetcode.com/problems/shortest-bridge/description/
 *
 * algorithms
 * Medium (54.39%)
 * Likes:    3922
 * Dislikes: 158
 * Total Accepted:    136.1K
 * Total Submissions: 246.4K
 * Testcase Example:  '[[0,1],[1,0]]'
 *
 * You are given an n x n binary matrix grid where 1 represents land and 0
 * represents water.
 *
 * An island is a 4-directionally connected group of 1's not connected to any
 * other 1's. There are exactly two islands in grid.
 *
 * You may change 0's to 1's to connect the two islands to form one island.
 *
 * Return the smallest number of 0's you must flip to connect the two
 * islands.
 *
 *
 * Example 1:
 *
 *
 * Input: grid = [[0,1],[1,0]]
 * Output: 1
 *
 *
 * Example 2:
 *
 *
 * Input: grid = [[0,1,0],[0,0,0],[0,0,1]]
 * Output: 2
 *
 *
 * Example 3:
 *
 *
 * Input: grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * n == grid.length == grid[i].length
 * 2 <= n <= 100
 * grid[i][j] is either 0 or 1.
 * There are exactly two islands in grid.
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        int m=grid[0].size();
        int first_x = -1, first_y = -1;
        // Find any land cell, and we treat it as a cell of island A.
        for (int i = 0; i < n; i++) {
            if (first_x != -1) break;
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    first_x = i;
                    first_y = j;
                    break;
                }
            }
        }

        // Recursively check the neighboring land cell of current cell grid[x][y] and add all
        // land cells of island A to bfs_queue.
        queue<pair<int, int>> bfs_queue;
        function<void(int, int)> dfs = [&](int x, int y) {
            grid[x][y] = 2;
            bfs_queue.push({x, y});
            vector<vector<int>>dd={{x + 1, y}, {x - 1, y}, {x, y + 1}, {x, y - 1}};
            for (int x=0;x<4;x++ ) {
                if (dd[x][0] >= 0 && dd[x][0] < n && dd[x][1] >= 0 && dd[x][1] < m && grid[dd[x][0]][dd[x][1]] == 1)
                    dfs(dd[x][0],dd[x][1]);
            }
        };

        // Add all land cells of island A to bfs_queue.
        dfs(first_x, first_y);

        int distance = 0;
        while (!bfs_queue.empty()) {
            queue<pair<int, int>> new_bfs;
            while (!bfs_queue.empty()) {
                auto [x, y] = bfs_queue.front(); bfs_queue.pop();
                vector<vector<int>>dd{{x + 1, y}, {x - 1, y}, {x, y + 1}, {x, y - 1}};
                for (int x=0;x<4;x++ ) {
                    if (dd[x][0] >= 0 && dd[x][0] < n && dd[x][1] >= 0 && dd[x][1] < m) {
                        if (grid[dd[x][0]][dd[x][1]] == 1)
                            return distance;
                        else if (grid[dd[x][0]][dd[x][1]] == 0) {
                            new_bfs.push({dd[x][0], dd[x][1]});
                            grid[dd[x][0]][dd[x][1]] = -1;
                        }
                    }
                }
            }

            // Once we finish one round without finding land cells of island B, we will
            // start the next round on all water cells that are 1 cell further away from
            // island A and increment the distance by 1.
            bfs_queue = new_bfs;
            distance++;
        }
        return 0;
    }
   

};
// @lc code=end
