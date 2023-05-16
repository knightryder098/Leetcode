/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 *
 * https://leetcode.com/problems/unique-paths-ii/description/
 *
 * algorithms
 * Medium (39.46%)
 * Likes:    6947
 * Dislikes: 436
 * Total Accepted:    679K
 * Total Submissions: 1.7M
 * Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
 *
 * You are given an m x n integer array grid. There is a robot initially
 * located at the top-left corner (i.e., grid[0][0]). The robot tries to move
 * to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only
 * move either down or right at any point in time.
 * 
 * An obstacle and space are marked as 1 or 0 respectively in grid. A path that
 * the robot takes cannot include any square that is an obstacle.
 * 
 * Return the number of possible unique paths that the robot can take to reach
 * the bottom-right corner.
 * 
 * The testcases are generated so that the answer will be less than or equal to
 * 2 * 10^9.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
 * Output: 2
 * Explanation: There is one obstacle in the middle of the 3x3 grid above.
 * There are two ways to reach the bottom-right corner:
 * 1. Right -> Right -> Down -> Down
 * 2. Down -> Down -> Right -> Right
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: obstacleGrid = [[0,1],[0,0]]
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == obstacleGrid.length
 * n == obstacleGrid[i].length
 * 1 <= m, n <= 100
 * obstacleGrid[i][j] is 0 or 1.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int helper(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp){
        if(i==0 and j==0){
            return (grid[0][0]==0)?1:0;
        }
        if(i<0 ||j<0||grid[i][j]==1)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int top=helper(i-1,j,grid,dp);
        int left=helper(i,j-1,grid,dp);
        return dp[i][j]=top+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size(),m=obstacleGrid[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return helper(n-1,m-1,obstacleGrid,dp);
    }
};
// @lc code=end


