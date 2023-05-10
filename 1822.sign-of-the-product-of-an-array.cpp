/*
 * @lc app=leetcode id=1822 lang=cpp
 *
 * [1822] Sign of the Product of an Array
 */

// @lc code=start
class Solution
{
public:
    int arraySign(vector<int> &nums)
    {
        int xx = 0;
        for (auto x : nums)
        {
            if (x < 0)
                xx++;
            if (x == 0)
                return 0;
        }
        // cout<<xx;
        if (xx % 2 == 0)
            return 1;
        else
            return -1;
    }
};
// @lc code=end
