/*
 * @lc app=leetcode id=1318 lang=cpp
 *
 * [1318] Minimum Flips to Make a OR b Equal to c
 *
 * https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/description/
 *
 * algorithms
 * Medium (66.00%)
 * Likes:    1077
 * Dislikes: 66
 * Total Accepted:    51.4K
 * Total Submissions: 73.9K
 * Testcase Example:  '2\n6\n5'
 *
 * Given 3 positives numbers a, b and c. Return the minimum flips required in
 * some bits of a and b to make ( a OR b == c ). (bitwise OR operation).
 * Flip operation consists of change any single bit 1 to 0 or change the bit 0
 * to 1 in their binary representation.
 *
 *
 * Example 1:
 *
 *
 *
 *
 * Input: a = 2, b = 6, c = 5
 * Output: 3
 * Explanation: After flips a = 1 , b = 4 , c = 5 such that (a OR b == c)
 *
 * Example 2:
 *
 *
 * Input: a = 4, b = 2, c = 7
 * Output: 1
 *
 *
 * Example 3:
 *
 *
 * Input: a = 1, b = 2, c = 3
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= a <= 10^9
 * 1 <= b <= 10^9
 * 1 <= c <= 10^9
 *
 */

// @lc code=start
class Solution
{
public:
    int minFlips(int a, int b, int c)
    {
        bitset<32> aa(a), bb(b), cc(c);
        int ct = 0;
        for (int i = 0; i < 32; i++)
        {
            if (cc[i] == bb[i] and bb[i] == aa[i])
                continue;
            if (cc[i] == 0)
            {
                // boths aar one
                if (bb[i] == aa[i] and bb[i] == 1)
                    ct += 2;
                else
                    ct += 1;
            }
            else
            {
                if (bb[i] == aa[i] and bb[i] == 0)
                    ct += 1;
            }
        }
        return ct;
    }
};
// @lc code=end
