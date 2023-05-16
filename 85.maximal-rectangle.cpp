/*
 * @lc app=leetcode id=85 lang=cpp
 *
 * [85] Maximal Rectangle
 *
 * https://leetcode.com/problems/maximal-rectangle/description/
 *
 * algorithms
 * Hard (44.87%)
 * Likes:    8566
 * Dislikes: 138
 * Total Accepted:    344.3K
 * Total Submissions: 766.6K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * Given a rows x cols binary matrix filled with 0's and 1's, find the largest
 * rectangle containing only 1's and return its area.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: matrix =
 * [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
 * Output: 6
 * Explanation: The maximal rectangle is shown in the above picture.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: matrix = [["0"]]
 * Output: 0
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: matrix = [["1"]]
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * rows == matrix.length
 * cols == matrix[i].length
 * 1 <= row, cols <= 200
 * matrix[i][j] is '0' or '1'.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                dp[i][j]=(matrix[i][j]=='1')?dp[i][j+1]+1:0;
            }
        }

        for(auto x:dp){for(auto yy:x){cout<<yy<<" ";}cout<<'\n';}
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int row=i,len=m;row<n and matrix[row][j]=='1';row++){
                    int width=row-i+1;
                    len=min(len,dp[row][j]);
                    ans=max(ans,width*len);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

