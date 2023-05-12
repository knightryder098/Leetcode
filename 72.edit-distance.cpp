/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 *
 * https://leetcode.com/problems/edit-distance/description/
 *
 * algorithms
 * Hard (54.52%)
 * Likes:    12458
 * Dislikes: 144
 * Total Accepted:    645.1K
 * Total Submissions: 1.2M
 * Testcase Example:  '"horse"\n"ros"'
 *
 * Given two strings word1 and word2, return the minimum number of operations
 * required to convert word1 to word2.
 * 
 * You have the following three operations permitted on a word:
 * 
 * 
 * Insert a character
 * Delete a character
 * Replace a character
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: word1 = "horse", word2 = "ros"
 * Output: 3
 * Explanation: 
 * horse -> rorse (replace 'h' with 'r')
 * rorse -> rose (remove 'r')
 * rose -> ros (remove 'e')
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: word1 = "intention", word2 = "execution"
 * Output: 5
 * Explanation: 
 * intention -> inention (remove 't')
 * inention -> enention (replace 'i' with 'e')
 * enention -> exention (replace 'n' with 'x')
 * exention -> exection (replace 'n' with 'c')
 * exection -> execution (insert 'u')
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= word1.length, word2.length <= 500
 * word1 and word2 consist of lowercase English letters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int helper(int i,int j,string &s,string &t,vector<vector<int>>&dp){
        if(i==0)return j;
        if(j==0)return i;

        if(dp[i][j]!=-1)return dp[i][j];

        if(s[i-1]==t[j-1])return dp[i][j]= helper(i-1,j-1,s,t,dp);
        else{
            int ins=1+helper(i,j-1,s,t,dp);
            int rep=1+helper(i-1,j-1,s,t,dp);
            int del=1+helper(i-1,j,s,t,dp);
            return dp[i][j]=min({ins,rep,del});
        }
    }
    int minDistance(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return helper(n,m,s,t,dp);
    }
};
// @lc code=end

