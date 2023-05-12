/*
 * @lc app=leetcode id=115 lang=cpp
 *
 * [115] Distinct Subsequences
 *
 * https://leetcode.com/problems/distinct-subsequences/description/
 *
 * algorithms
 * Hard (44.61%)
 * Likes:    5301
 * Dislikes: 201
 * Total Accepted:    292.4K
 * Total Submissions: 654.7K
 * Testcase Example:  '"rabbbit"\n"rabbit"'
 *
 * Given two strings s and t, return the number of distinct subsequences of s
 * which equals t.
 * 
 * The test cases are generated so that the answer fits on a 32-bit signed
 * integer.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "rabbbit", t = "rabbit"
 * Output: 3
 * Explanation:
 * As shown below, there are 3 ways you can generate "rabbit" from s.
 * rabbbit
 * rabbbit
 * rabbbit
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "babgbag", t = "bag"
 * Output: 5
 * Explanation:
 * As shown below, there are 5 ways you can generate "bag" from s.
 * babgbag
 * babgbag
 * babgbag
 * babgbag
 * babgbag
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length, t.length <= 1000
 * s and t consist of English letters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int helper(int i,int j,string&s,string &t,vector<vector<int>>&dp){
        if(j==0)return 1;
        if(i==0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i-1]==t[j-1])return dp[i][j]=helper(i-1,j-1,s,t,dp)+helper(i-1,j,s,t,dp);
        else
        return dp[i][j]=helper(i-1,j,s,t,dp);
    }
    int numDistinct(string s, string t) {
        int n=s.size(),m=t.size();
        // vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        // return helper(n,m,s,t,dp);

        vector<vector<double>>dp(n+1,vector<double>(m+1,0));
        for(int i=0;i<=n;i++)dp[i][0]=1;
        for(int j=1;j<=m;j++)dp[0][j]=0;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1])dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                else
                dp[i][j]=dp[i-1][j];
            }
        }

        return (int)dp[n][m];

    }
};
// @lc code=end

