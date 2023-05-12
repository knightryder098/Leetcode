/*
 * @lc app=leetcode id=44 lang=cpp
 *
 * [44] Wildcard Matching
 *
 * https://leetcode.com/problems/wildcard-matching/description/
 *
 * algorithms
 * Hard (26.97%)
 * Likes:    6865
 * Dislikes: 291
 * Total Accepted:    471.6K
 * Total Submissions: 1.7M
 * Testcase Example:  '"aa"\n"a"'
 *
 * Given an input string (s) and a pattern (p), implement wildcard pattern
 * matching with support for '?' and '*' where:
 *
 *
 * '?' Matches any single character.
 * '*' Matches any sequence of characters (including the empty sequence).
 *
 *
 * The matching should cover the entire input string (not partial).
 *
 *
 * Example 1:
 *
 *
 * Input: s = "aa", p = "a"
 * Output: false
 * Explanation: "a" does not match the entire string "aa".
 *
 *
 * Example 2:
 *
 *
 * Input: s = "aa", p = "*"
 * Output: true
 * Explanation: '*' matches any sequence.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "cb", p = "?a"
 * Output: false
 * Explanation: '?' matches 'c', but the second letter is 'a', which does not
 * match 'b'.
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= s.length, p.length <= 2000
 * s contains only lowercase English letters.
 * p contains only lowercase English letters, '?' or '*'.
 *
 *
 */

// @lc code=start
class Solution
{
public:
    bool helper(int i, int j, string &s, string &t, vector<vector<int>> &dp)
    {
        if(i==0 and j==0)return 1;
        if(i==0 and j>0)return 0;
        if(j==0 and i>0){
            for(int x=0;x<i;x++)if(s[x]!='*')return 0;

            return 1;
        }
        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i - 1] == t[j - 1] || s[i - 1] == '?')
            return dp[i][j] = helper(i - 1, j - 1, s, t, dp);
        else if (s[i - 1] == '*')
            return dp[i][j] = (helper(i - 1, j, s, t,dp) | helper(i , j - 1, s, t, dp));
        else
            return dp[i][j] = 0;
    }
    bool isMatch(string s, string p)
    {
        int n = s.size(), m = p.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return helper( m,n, p, s, dp);
    }
};
// @lc code=end
