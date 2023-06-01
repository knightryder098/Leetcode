/*
 * @lc app=leetcode id=1034 lang=cpp
 *
 * [1034] Coloring A Border
 *
 * https://leetcode.com/problems/coloring-a-border/description/
 *
 * algorithms
 * Medium (49.22%)
 * Likes:    624
 * Dislikes: 794
 * Total Accepted:    29.9K
 * Total Submissions: 60.6K
 * Testcase Example:  '[[1,1],[1,2]]\n0\n0\n3'
 *
 * You are given an m x n integer matrix grid, and three integers row, col, and
 * color. Each value in the grid represents the color of the grid square at
 * that location.
 * 
 * Two squares belong to the same connected component if they have the same
 * color and are next to each other in any of the 4 directions.
 * 
 * The border of a connected component is all the squares in the connected
 * component that are either 4-directionally adjacent to a square not in the
 * component, or on the boundary of the grid (the first or last row or
 * column).
 * 
 * You should color the border of the connected component that contains the
 * square grid[row][col] with color.
 * 
 * Return the final grid.
 * 
 * 
 * Example 1:
 * Input: grid = [[1,1],[1,2]], row = 0, col = 0, color = 3
 * Output: [[3,3],[3,2]]
 * Example 2:
 * Input: grid = [[1,2,2],[2,3,2]], row = 0, col = 1, color = 3
 * Output: [[1,3,3],[2,3,3]]
 * Example 3:
 * Input: grid = [[1,1,1],[1,1,1],[1,1,1]], row = 1, col = 1, color = 2
 * Output: [[2,2,2],[2,1,2],[2,2,2]]
 * 
 * 
 * Constraints:
 * 
 * 
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 50
 * 1 <= grid[i][j], color <= 1000
 * 0 <= row < m
 * 0 <= col < n
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void helper(int i,int j,int newclr,int oldclr,vector<vector<int>>&grid){
        grid[i][j]=newclr;
        int dr[]={0,-1,0,1};
        int dc[]={-1,0,1,0};
        for(int x=0;x<4;x++){
            int ni=i+dr[x];
            int nj=j+dc[x];
            if(ni<0||nj<0||ni==grid.size()||nj==grid[0].size()||grid[ni][nj]==newclr)
            if(grid[ni][nj]==oldclr)helper(ni,nj,newclr,oldclr,grid);
        }
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int oldclr=grid[row][col];
        helper(row,col,color,oldclr,grid);
        return grid;
    }
};
// @lc code=end

