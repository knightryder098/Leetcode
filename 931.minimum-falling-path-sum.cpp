/*
 * @lc app=leetcode id=931 lang=cpp
 *
 * [931] Minimum Falling Path Sum
 *
 * https://leetcode.com/problems/minimum-falling-path-sum/description/
 *
 * algorithms
 * Medium (69.11%)
 * Likes:    4705
 * Dislikes: 121
 * Total Accepted:    243.7K
 * Total Submissions: 352.6K
 * Testcase Example:  '[[2,1,3],[6,5,4],[7,8,9]]'
 *
 * Given an n x n array of integers matrix, return the minimum sum of any
 * falling path through matrix.
 * 
 * A falling path starts at any element in the first row and chooses the
 * element in the next row that is either directly below or diagonally
 * left/right. Specifically, the next element from position (row, col) will be
 * (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
 * Output: 13
 * Explanation: There are two falling paths with a minimum sum as shown.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: matrix = [[-19,57],[-40,-5]]
 * Output: -59
 * Explanation: The falling path with a minimum sum is shown.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == matrix.length == matrix[i].length
 * 1 <= n <= 100
 * -100 <= matrix[i][j] <= 100
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int helper(int i,int j,vector<vector<int>>& matrix){
        if(i==matrix.size()-1){
            if(j>=0 and j<matrix[0].size()){
                return matrix[i][j];
            }
            else return 1e7;
        }
        if(j<0|| j>=matrix[0].size()){
            return 1e7;
        }

        return matrix[i][j]+min(helper(i+1,j-1,matrix),min(helper(i+1,j,matrix),helper(i+1,j+1,matrix)));
    }

    int helper2(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>&dp){
        if(i==matrix.size()-1){
            if(j>=0 and j<matrix[0].size()){

                return matrix[i][j];
            }
            else return 1e7;
        }
        if(j<0|| j>=matrix[0].size()){
            return 1e7;
        }

        if(dp[i][j]!=-1)return dp[i][j];

        return dp[i][j]= matrix[i][j]+min(helper2(i+1,j-1,matrix,dp),min(helper2(i+1,j,matrix,dp),helper2(i+1,j+1,matrix,dp)));
    }


    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int ans=1e9;
        //basic recursive solution
        // for(int i=0;i<m;i++){
        //     ans=min(ans,helper(0,i,matrix));
        // }

        //memoization top down
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i=0;i<m;i++){
            ans=min(ans,helper2(0,i,matrix,dp));
        }

        return ans;
    }
};
// @lc code=end

