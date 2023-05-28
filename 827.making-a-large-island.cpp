/*
 * @lc app=leetcode id=827 lang=cpp
 *
 * [827] Making A Large Island
 *
 * https://leetcode.com/problems/making-a-large-island/description/
 *
 * algorithms
 * Hard (44.96%)
 * Likes:    3171
 * Dislikes: 60
 * Total Accepted:    130.3K
 * Total Submissions: 289.6K
 * Testcase Example:  '[[1,0],[0,1]]'
 *
 * You are given an n x n binary matrix grid. You are allowed to change at most
 * one 0 to be 1.
 *
 * Return the size of the largest island in grid after applying this
 * operation.
 *
 * An island is a 4-directionally connected group of 1s.
 *
 *
 * Example 1:
 *
 *
 * Input: grid = [[1,0],[0,1]]
 * Output: 3
 * Explanation: Change one 0 to 1 and connect two 1s, then we get an island
 * with area = 3.
 *
 *
 * Example 2:
 *
 *
 * Input: grid = [[1,1],[1,0]]
 * Output: 4
 * Explanation: Change the 0 to 1 and make the island bigger, only one island
 * with area = 4.
 *
 * Example 3:
 *
 *
 * Input: grid = [[1,1],[1,1]]
 * Output: 4
 * Explanation: Can't change any 0 to 1, only one island with area = 4.
 *
 *
 *
 * Constraints:
 *
 *
 * n == grid.length
 * n == grid[i].length
 * 1 <= n <= 500
 * grid[i][j] is either 0 or 1.
 *
 */

// @lc code=start
class Solution
{
public:
    vector<int> parent, height;
    int findparent(int a)
    {
        if (a == parent[a])
            return a;
        return parent[a] = findparent(parent[a]);
    }
    void unionab(int a, int b)
    {
        int pa = findparent(a);
        int pb = findparent(b);
        if (pa == pb)
            return;
        if (height[pa] < height[pb])
        {
            parent[pa] = pb;
            height[pb] += height[pa];
        }
        else
        {
            parent[pb] = pa;
            height[pa] += height[pb];
        }
    }
    int largestIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int tot = n * m;
        parent.resize(tot);
        iota(parent.begin(), parent.end(), 0);
        height.resize(tot, 1);
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    for (int x = 0; x < 4; x++)
                    {
                        int ni = i + dr[x];
                        int nj = j + dc[x];
                        if (ni >= 0 and nj >= 0 and ni < n and nj < m and grid[ni][nj] == 1)
                        {
                            unionab(m * i + j, m * ni + nj);
                        }
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 0)
                {
                    set<int> possible;
                    for (int x = 0; x < 4; x++)
                    {
                        int ni = i + dr[x];
                        int nj = j + dc[x];
                        if(ni<0||nj<0||ni==n||nj==m||grid[ni][nj]==0)continue;
                        possible.insert(findparent(m * ni + nj));
                        
                    }
                    int tmp = 1;
                    for (auto x : possible)
                    {
                        tmp += height[x];
                    }
                    ans = max(ans, tmp);
                }
            }
        }

        for (int i = 0; i < tot; i++)
        {
            ans = max(ans, height[i]);
        }
        return ans;
    }
};
// @lc code=end
