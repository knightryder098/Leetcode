/*
 * @lc app=leetcode id=89 lang=cpp
 *
 * [89] Gray Code
 *
 * https://leetcode.com/problems/gray-code/description/
 *
 * algorithms
 * Medium (57.29%)
 * Likes:    1890
 * Dislikes: 2502
 * Total Accepted:    261.8K
 * Total Submissions: 456.9K
 * Testcase Example:  '2'
 *
 * An n-bit gray code sequence is a sequence of 2^n integers where:
 *
 *
 * Every integer is in the inclusive range [0, 2^n - 1],
 * The first integer is 0,
 * An integer appears no more than once in the sequence,
 * The binary representation of every pair of adjacent integers differs by
 * exactly one bit, and
 * The binary representation of the first and last integers differs by exactly
 * one bit.
 *
 *
 * Given an integer n, return any valid n-bit gray code sequence.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 2
 * Output: [0,1,3,2]
 * Explanation:
 * The binary representation of [0,1,3,2] is [00,01,11,10].
 * - 00 and 01 differ by one bit
 * - 01 and 11 differ by one bit
 * - 11 and 10 differ by one bit
 * - 10 and 00 differ by one bit
 * [0,2,3,1] is also a valid gray code sequence, whose binary representation is
 * [00,10,11,01].
 * - 00 and 10 differ by one bit
 * - 10 and 11 differ by one bit
 * - 11 and 01 differ by one bit
 * - 01 and 00 differ by one bit
 *
 *
 * Example 2:
 *
 *
 * Input: n = 1
 * Output: [0,1]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 16
 *
 *
 */

// @lc code=start
class Solution
{
public:
    auto getgray(int n)
    {
        vector<string> ans;
        ans.push_back("0");
        ans.push_back("1");
        if (n == 1)
            return ans;
        for (int i = 2; i < (1 << n); i <<= 1)
        {
            int j;
            for (j = i - 1; j >= 0; j--)
                ans.push_back(ans[j]);
            for (j = 0; j < i; j++)
                ans[j] = '0' + ans[j];
            for (j = i; j < 2 * i; j++)
                ans[j] = '1' + ans[j];
        }
        return ans;
    }
    auto getdeci(string s)
    {
        int ans = 0;
        int p = 0;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (s[i] == '1')
            {
                ans += (1 << p);
            }
            p++;
        }
        return ans;
    }
    void helper(bitset<32>&bits,vector<int>&res,int n){
        if(n==0){
            res.push_back(bits.to_ulong());
        }
        else{
            helper(bits,res,n-1);
            bits.flip(n-1);
            helper(bits,res,n-1);
        }
    }
    vector<int> grayCode(int n)
    {
        // vector<string> ans = getgray(n);
        // vector<int> res;
        // for (auto x : ans)
        // {
        //     // cout << x << " ";
        //     res.push_back(getdeci(x));
        // }
        // return res;
        bitset<32>ans;
        vector<int>res;
        helper(ans,res,n);
        return res;
    }
};
// @lc code=end
