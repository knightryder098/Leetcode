/*
 * @lc app=leetcode id=400 lang=cpp
 *
 * [400] Nth Digit
 *
 * https://leetcode.com/problems/nth-digit/description/
 *
 * algorithms
 * Medium (34.17%)
 * Likes:    884
 * Dislikes: 1819
 * Total Accepted:    85.3K
 * Total Submissions: 249.5K
 * Testcase Example:  '3'
 *
 * Given an integer n, return the n^th digit of the infinite integer sequence
 * [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...].
 *
 *
 * Example 1:
 *
 *
 * Input: n = 3
 * Output: 3
 *
 *
 * Example 2:
 *
 *
 * Input: n = 11
 * Output: 0
 * Explanation: The 11^th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
 * 11, ... is a 0, which is part of the number 10.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 2^31 - 1
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int findNthDigit(int n)
    {
        long long base = 9, digits = 1;
        while (n - base * digits > 0)
        {
            n -= base * digits;
            base *= 10;
            digits++;
        }
        long long num = pow(10, digits - 1) + (n - 1) / digits;
        int index = (n - 1) % digits;
        return to_string(num)[index] - '0';
    }
};
// @lc code=end
