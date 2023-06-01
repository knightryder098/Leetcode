/*
 * @lc app=leetcode id=522 lang=cpp
 *
 * [522] Longest Uncommon Subsequence II
 *
 * https://leetcode.com/problems/longest-uncommon-subsequence-ii/description/
 *
 * algorithms
 * Medium (40.57%)
 * Likes:    456
 * Dislikes: 1219
 * Total Accepted:    47.6K
 * Total Submissions: 117.2K
 * Testcase Example:  '["aba","cdc","eae"]'
 *
 * Given an array of strings strs, return the length of the longest uncommon
 * subsequence between them. If the longest uncommon subsequence does not
 * exist, return -1.
 * 
 * An uncommon subsequence between an array of strings is a string that is a
 * subsequence of one string but not the others.
 * 
 * A subsequence of a string s is a string that can be obtained after deleting
 * any number of characters from s.
 * 
 * 
 * For example, "abc" is a subsequence of "aebdc" because you can delete the
 * underlined characters in "aebdc" to get "abc". Other subsequences of "aebdc"
 * include "aebdc", "aeb", and "" (empty string).
 * 
 * 
 * 
 * Example 1:
 * Input: strs = ["aba","cdc","eae"]
 * Output: 3
 * Example 2:
 * Input: strs = ["aaa","aaa","aa"]
 * Output: -1
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= strs.length <= 50
 * 1 <= strs[i].length <= 10
 * strs[i] consists of lowercase English letters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool is_good(const string &a,const string&b){                    
    int i = 0, j = 0, na = a.size(), nb = b.size();
    while(i < na && j < nb)
      if(a[i] == b[j++]) i++;
      
    return i == na;
  }
  
  int findLUSlength(vector<string>& strs) {
    map<int,unordered_map<string,int>> table;                   
    
    for(auto &s: strs) table[s.size()][s]++;                   
    
    for(auto it = table.rbegin();it != table.rend();it++)           
      for(auto &s: it->second){
        if(s.second == 1){ 
          for(auto itn = table.rbegin(); itn != it; itn++)   
            for(auto &S: itn->second)
              if(is_good(s.first,S.first)) goto mark;              
               return it->first;                                        
        }
        mark:;
      }
       
    return -1;
  }
};
// @lc code=end

