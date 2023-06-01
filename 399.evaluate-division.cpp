/*
 * @lc app=leetcode id=399 lang=cpp
 *
 * [399] Evaluate Division
 *
 * https://leetcode.com/problems/evaluate-division/description/
 *
 * algorithms
 * Medium (59.71%)
 * Likes:    7181
 * Dislikes: 639
 * Total Accepted:    339.6K
 * Total Submissions: 566.6K
 * Testcase Example:  '[["a","b"],["b","c"]]\n' +
  '[2.0,3.0]\n' +
  '[["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]'
 *
 * You are given an array of variable pairs equations and an array of real
 * numbers values, where equations[i] = [Ai, Bi] and values[i] represent the
 * equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a
 * single variable.
 * 
 * You are also given some queries, where queries[j] = [Cj, Dj] represents the
 * j^th query where you must find the answer for Cj / Dj = ?.
 * 
 * Return the answers to all queries. If a single answer cannot be determined,
 * return -1.0.
 * 
 * Note: The input is always valid. You may assume that evaluating the queries
 * will not result in division by zero and that there is no contradiction.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries =
 * [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
 * Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
 * Explanation: 
 * Given: a / b = 2.0, b / c = 3.0
 * queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
 * return: [6.0, 0.5, -1.0, 1.0, -1.0 ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: equations = [["a","b"],["b","c"],["bc","cd"]], values =
 * [1.5,2.5,5.0], queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
 * Output: [3.75000,0.40000,5.00000,0.20000]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: equations = [["a","b"]], values = [0.5], queries =
 * [["a","b"],["b","a"],["a","c"],["x","y"]]
 * Output: [0.50000,2.00000,-1.00000,-1.00000]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= equations.length <= 20
 * equations[i].length == 2
 * 1 <= Ai.length, Bi.length <= 5
 * values.length == equations.length
 * 0.0 < values[i] <= 20.0
 * 1 <= queries.length <= 20
 * queries[i].length == 2
 * 1 <= Cj.length, Dj.length <= 5
 * Ai, Bi, Cj, Dj consist of lower case English letters and digits.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
       
// TC - (N + Q*V)
// SC - (N + V)
// Q is the number of queries and V is the number of vertices in the graph,N is the number of equations.


void dfs(string s,string e,map<string,double>& mp,map<string,vector<string>>& graph,double& val,map<string,int>& vis,bool& check){

        vis[s]=1;
    
        if(check==true)
            return ;

        for(auto it:graph[s]){
            if(vis[it]!=1){
               
                val*=mp[s+"->"+it];
                if(e==it){
                    
                    check=true;
                    return ;
                }

                dfs(it,e,mp,graph,val,vis,check);

                if(check == true)
                    return ;
                
                else
                    val/=mp[s+"->"+it];
                
            }
        }
       
        
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

        vector<double> ans;
        map<string,double> mp;
        map<string,vector<string>> graph;

        for(int i=0;i<equations.size();i++){

            string u=equations[i][0];
            string v=equations[i][1];

            mp[u+"->"+v]=values[i];
            mp[v+"->"+u]=1/values[i];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        for(int i=0;i<queries.size();i++){

            string s=queries[i][0];
            string e=queries[i][1];

            if(graph.find(s) == graph.end()|| graph.find(e) == graph.end())
                ans.push_back(-1);
            
            else{
                
                double val=1;
                map<string,int> vis;
                bool check=false;

                if(s == e)
                    check=true;
                
                else
                dfs(s,e,mp,graph,val,vis,check);

                if(check == true)
                ans.push_back(val);

                else
                    ans.push_back(-1);
                
            }
        }
        return ans;
    }
};
// @lc code=end

