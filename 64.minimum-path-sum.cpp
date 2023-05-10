/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 *
 * https://leetcode.com/problems/minimum-path-sum/description/
 *
 * algorithms
 * Medium (62.05%)
 * Likes:    10737
 * Dislikes: 138
 * Total Accepted:    932.3K
 * Total Submissions: 1.5M
 * Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
 *
 * Given a m x n grid filled with non-negative numbers, find a path from top
 * left to bottom right, which minimizes the sum of all numbers along its
 * path.
 * 
 * Note: You can only move either down or right at any point in time.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
 * Output: 7
 * Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: grid = [[1,2,3],[4,5,6]]
 * Output: 12
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 200
 * 0 <= grid[i][j] <= 100
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int helper(vector<vector<int>>& grid,int i,int j,vector<vector<int>>&dp){
        if(i==0 && j==0){
            return grid[i][j];
        }
        if(i<0 || j<0){
            return INT_MAX;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        return dp[i][j]=grid[i][j]+min(helper(grid,i-1,j,dp),helper(grid,i,j-1,dp));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        //top down
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return helper(grid,n-1,m-1,dp);

        //bottom up
        vector<vector<int>>xxx(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
                if(i==0 and j==0)xxx[0][0]=grid[i][j];
                else if(i==0)xxx[i][j]=grid[i][j]+xxx[i][j-1];
                else if(j==0)xxx[i][j]=grid[i][j]+xxx[i-1][j];
                else xxx[i][j]=grid[i][j]+min(xxx[i-1][j],xxx[i][j-1]);
           }
        }
        return xxx[n-1][m-1];

        //space optimized
        vector<int>prev(m,0);
        prev[0]=grid[0][0];
        for(int i=0;i<n;i++){
            vector<int>curr(m,0);
            for(int j=0;j<m;j++){
                if(i==0 and j==0)curr[0]=grid[i][j];
                else if(i==0)curr[j]=grid[i][j]+curr[j-1];
                else if(j==0)curr[j]=grid[i][j]+prev[j];
                else curr[j]=grid[i][j]+min(prev[j],curr[j-1]);
            }
            prev=curr;
        }
        return prev[m-1];
    }
};
// @lc code=end

