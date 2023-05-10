/*
 * @lc app=leetcode id=1456 lang=cpp
 *
 * [1456] Maximum Number of Vowels in a Substring of Given Length
 *
 * https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/description/
 *
 * algorithms
 * Medium (58.22%)
 * Likes:    1584
 * Dislikes: 62
 * Total Accepted:    82.4K
 * Total Submissions: 137.5K
 * Testcase Example:  '"abciiidef"\n3'
 *
 * Given a string s and an integer k, return the maximum number of vowel
 * letters in any substring of s with length k.
 * 
 * Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "abciiidef", k = 3
 * Output: 3
 * Explanation: The substring "iii" contains 3 vowel letters.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "aeiou", k = 2
 * Output: 2
 * Explanation: Any substring of length 2 contains 2 vowels.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "leetcode", k = 3
 * Output: 2
 * Explanation: "lee", "eet" and "ode" contain 2 vowels.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^5
 * s consists of lowercase English letters.
 * 1 <= k <= s.length
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int maxVowels(string s, int k) {
         map<char,int>windows;
        for(int i=0;i<k;i++){
            windows[s[i]]++;
        }
        int ans=windows['a']+windows['e']+windows['i']+windows['o']+windows['u'];
        for(int i=k;i<s.length();i++){
            windows[s[i-k]]--;
            windows[s[i]]++;
            int tmp=windows['a']+windows['e']+windows['i']+windows['o']+windows['u'];
            ans=max(ans,tmp);
        }
        return ans;
    }
};
// @lc code=end

