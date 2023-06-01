/*
 * @lc app=leetcode id=372 lang=cpp
 *
 * [372] Super Pow
 *
 * https://leetcode.com/problems/super-pow/description/
 *
 * algorithms
 * Medium (36.13%)
 * Likes:    745
 * Dislikes: 1327
 * Total Accepted:    59.8K
 * Total Submissions: 165.7K
 * Testcase Example:  '2\n[3]'
 *
 * Your task is to calculate a^b mod 1337 where a is a positive integer and b
 * is an extremely large positive integer given in the form of an array.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: a = 2, b = [3]
 * Output: 8
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: a = 2, b = [1,0]
 * Output: 1024
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: a = 1, b = [4,3,3,8,5,2]
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= a <= 2^31 - 1
 * 1 <= b.length <= 2000
 * 0 <= b[i] <= 9
 * b does not contain leading zeros.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int mod=1337;
    int power(int a,int b){
        if(a==0)return 0;
        a%=mod;
        int res=1;
        while(b){
           if(b&1)res=(res*a)%mod;
           a=(a*a)%mod;
           b>>=1;

        }
        return res;
    }
    int superPow(int a, vector<int>& b) {
        int n=b.size();
        if(n==0)return 1;
        int ld=b[n-1];
        b.pop_back();
        return power(superPow(a,b),10)*power(a,ld)%mod;
    }
};
// @lc code=end

