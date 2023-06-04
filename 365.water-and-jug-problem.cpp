/*
 * @lc app=leetcode id=365 lang=cpp
 *
 * [365] Water and Jug Problem
 *
 * https://leetcode.com/problems/water-and-jug-problem/description/
 *
 * algorithms
 * Medium (37.96%)
 * Likes:    1206
 * Dislikes: 1348
 * Total Accepted:    82.2K
 * Total Submissions: 215.9K
 * Testcase Example:  '3\n5\n4'
 *
 * You are given two jugs with capacities jug1Capacity and jug2Capacity liters.
 * There is an infinite amount of water supply available. Determine whether it
 * is possible to measure exactly targetCapacity liters using these two jugs.
 *
 * If targetCapacity liters of water are measurable, you must have
 * targetCapacity liters of water contained within one or both buckets by the
 * end.
 *
 * Operations allowed:
 *
 *
 * Fill any of the jugs with water.
 * Empty any of the jugs.
 * Pour water from one jug into another till the other jug is completely full,
 * or the first jug itself is empty.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: jug1Capacity = 3, jug2Capacity = 5, targetCapacity = 4
 * Output: true
 * Explanation: The famous Die Hard example
 *
 *
 * Example 2:
 *
 *
 * Input: jug1Capacity = 2, jug2Capacity = 6, targetCapacity = 5
 * Output: false
 *
 *
 * Example 3:
 *
 *
 * Input: jug1Capacity = 1, jug2Capacity = 2, targetCapacity = 3
 * Output: true
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= jug1Capacity, jug2Capacity, targetCapacity <= 10^6
 *
 *
 */

// @lc code=start
class Solution
{
public:
    bool helper(int tot, int a, int b, int curr, int target, vector<int> &dp)
    {
        if (curr > tot || curr < 0 || dp[curr])
            return false;
        dp[curr] = 1;
        if (curr == target)
            return true;
        return helper(tot, a, b, curr + a, target, dp) | helper(tot, a, b, curr - a, target, dp) | helper(tot, a, b, curr + b, target, dp) | helper(tot, a, b, curr - b, target, dp);
    }
    bool canMeasureWater(int x, int y, int z)
    {
        int tot = x + y;
        vector<int> dp(tot + 1, 0);
        return helper(tot, x, y, 0, z, dp);
    }
};
// @lc code=end
