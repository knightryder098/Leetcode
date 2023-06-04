/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 *
 * https://leetcode.com/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (60.98%)
 * Likes:    3810
 * Dislikes: 303
 * Total Accepted:    683.6K
 * Total Submissions: 1.1M
 * Testcase Example:  '3'
 *
 * Given an integer rowIndex, return the rowIndex^th (0-indexed) row of the
 * Pascal's triangle.
 *
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it as shown:
 *
 *
 * Example 1:
 * Input: rowIndex = 3
 * Output: [1,3,3,1]
 * Example 2:
 * Input: rowIndex = 0
 * Output: [1]
 * Example 3:
 * Input: rowIndex = 1
 * Output: [1,1]
 *
 *
 * Constraints:
 *
 *
 * 0 <= rowIndex <= 33
 *
 *
 *
 * Follow up: Could you optimize your algorithm to use only O(rowIndex) extra
 * space?
 *
 */

// @lc code=start
class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> prev(1, 1);
        for (int i = 1; i <=rowIndex; i++)
        {
            vector<int> tmp(i + 1, 1);
            for (int j = 1; j < i; j++)
            {
                tmp[j] = prev[j] + prev[j - 1];
            }
            prev = tmp;
            
        }
        return prev;
    }
};
// @lc code=end
