/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 *
 * https://leetcode.com/problems/regular-expression-matching/description/
 *
 * algorithms
 * Hard (28.01%)
 * Likes:    10584
 * Dislikes: 1741
 * Total Accepted:    812.8K
 * Total Submissions: 2.9M
 * Testcase Example:  '"aa"\n"a"'
 *
 * Given an input string s and a pattern p, implement regular expression
 * matching with support for '.' and '*' where:
 *
 *
 * '.' Matches any single character.​​​​
 * '*' Matches zero or more of the preceding element.
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
 * Input: s = "aa", p = "a*"
 * Output: true
 * Explanation: '*' means zero or more of the preceding element, 'a'.
 * Therefore, by repeating 'a' once, it becomes "aa".
 *
 *
 * Example 3:
 *
 *
 * Input: s = "ab", p = ".*"
 * Output: true
 * Explanation: ".*" means "zero or more (*) of any character (.)".
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 20
 * 1 <= p.length <= 20
 * s contains only lowercase English letters.
 * p contains only lowercase English letters, '.', and '*'.
 * It is guaranteed for each appearance of the character '*', there will be a
 * previous valid character to match.
 *
 *
 */

// @lc code=start
class Solution
{
public:
    bool helper(int i, int j, string &s, string &p, vector<vector<int>> &dp)
    {

        int n = s.size(), m = p.size();

        if (j == m)
            return i == n;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (p[j + 1] == '*')
        {
            if (helper(i, j + 2, s, p, dp) || (i < n and (s[i] == p[j] || p[j] == '.') and helper(i + 1, j, s, p, dp)))
                return dp[i][j] = 1;
        }
        else if (i < n and (s[i] == p[j] || p[j] == '.') and helper(i + 1, j + 1, s, p, dp))
            return dp[i][j] = 1;

        return dp[i][j] = false;
    }
    bool isMatch(string s, string p)
    {
        int n = s.size(), m = p.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return helper(0, 0, s, p, dp);
    }
};
// @lc code=end
