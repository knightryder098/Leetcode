/*
 * @lc app=leetcode id=902 lang=cpp
 *
 * [902] Numbers At Most N Given Digit Set
 *
 * https://leetcode.com/problems/numbers-at-most-n-given-digit-set/description/
 *
 * algorithms
 * Hard (41.49%)
 * Likes:    1232
 * Dislikes: 95
 * Total Accepted:    40.3K
 * Total Submissions: 97K
 * Testcase Example:  '["1","3","5","7"]\n100'
 *
 * Given an array of digits which is sorted in non-decreasing order. You can
 * write numbers using each digits[i] as many times as we want. For example, if
 * digits = ['1','3','5'], we may write numbers such as '13', '551', and
 * '1351315'.
 *
 * Return the number of positive integers that can be generated that are less
 * than or equal to a given integer n.
 *
 *
 * Example 1:
 *
 *
 * Input: digits = ["1","3","5","7"], n = 100
 * Output: 20
 * Explanation:
 * The 20 numbers that can be written are:
 * 1, 3, 5, 7, 11, 13, 15, 17, 31, 33, 35, 37, 51, 53, 55, 57, 71, 73, 75,
 * 77.
 *
 *
 * Example 2:
 *
 *
 * Input: digits = ["1","4","9"], n = 1000000000
 * Output: 29523
 * Explanation:
 * We can write 3 one digit numbers, 9 two digit numbers, 27 three digit
 * numbers,
 * 81 four digit numbers, 243 five digit numbers, 729 six digit numbers,
 * 2187 seven digit numbers, 6561 eight digit numbers, and 19683 nine digit
 * numbers.
 * In total, this is 29523 integers that can be written using the digits
 * array.
 *
 *
 * Example 3:
 *
 *
 * Input: digits = ["7"], n = 8
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= digits.length <= 9
 * digits[i].length == 1
 * digits[i] is a digit from '1' to '9'.
 * All the values in digits are unique.
 * digits is sorted in non-decreasing order.
 * 1 <= n <= 10^9
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int dp[11][2][2];
    int helper(int idx, int tight, int state, const string &s, vector<int> &digit)
    {
        int n = s.size();
        if (idx == n)
            return 1;

        if(dp[idx][tight][state]!=-1)return dp[idx][tight][state];
        int ans = 0;

        if (state == 0)
        {
            int upper = tight ? s[idx] - '0' : 9;
            ans = helper(idx + 1, 0, 0, s, digit);
            for (auto x : digit)
            {
                if (x > upper)
                    continue;
                ans += helper(idx + 1, tight & (x == upper), 1, s, digit);
            }
        }
        else
        {
            int upper = tight ? s[idx] - '0' : 9;
            for (auto x : digit)
            {
                if (x > upper)
                    continue;
                ans += helper(idx + 1, tight & (x == upper), 1, s, digit);
            }
        }
        return dp[idx][tight][state]= ans;
    }
    int atMostNGivenDigitSet(vector<string> &digits, int n)
    {
        vector<int> dig;
        for (auto x : digits)
        {
            dig.push_back(x[0] - '0');
        }
        memset(dp,-1,sizeof(dp));
        return helper(0, 1, 0, to_string(n), dig)-1;
    }
};
// @lc code=end
