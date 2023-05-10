/*
 * @lc app=leetcode id=1289 lang=cpp
 *
 * [1289] Minimum Falling Path Sum II
 *
 * https://leetcode.com/problems/minimum-falling-path-sum-ii/description/
 *
 * algorithms
 * Hard (58.47%)
 * Likes:    1385
 * Dislikes: 78
 * Total Accepted:    41.1K
 * Total Submissions: 70.4K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given an n x n integer matrix grid, return the minimum sum of a falling path
 * with non-zero shifts.
 * 
 * A falling path with non-zero shifts is a choice of exactly one element from
 * each row of grid such that no two elements chosen in adjacent rows are in
 * the same column.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: arr = [[1,2,3],[4,5,6],[7,8,9]]
 * Output: 13
 * Explanation: 
 * The possible falling paths are:
 * [1,5,9], [1,5,7], [1,6,7], [1,6,8],
 * [2,4,8], [2,4,9], [2,6,7], [2,6,8],
 * [3,4,8], [3,4,9], [3,5,7], [3,5,9]
 * The falling path with the smallest sum is [1,5,7], so the answer is 13.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: grid = [[7]]
 * Output: 7
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == grid.length == grid[i].length
 * 1 <= n <= 200
 * -99 <= grid[i][j] <= 99
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int helper(int i,int j,vector<vector<int>>& grid,vector<vector<int>>&dp){
        int n=grid.size();
        int m=grid[0].size();
        if(i==n-1){
            return grid[i][j];
        }
        if(j<0 || j>=m){
            return 1e7;
        }

        if(dp[i][j]!=-1)return dp[i][j];

        int tmp=1e7;
        for(int x=0;x<m;x++){
            if(x!=j){
                tmp=min(tmp,helper(i+1,x,grid,dp));
            }
        }
        return dp[i][j]=tmp+grid[i][j];
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=1e9;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int j=0;j<m;j++){
            ans=min(ans,helper(0,j,grid,dp));
        }
        return ans;
    }
};
// @lc code=end

