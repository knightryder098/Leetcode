/*
 * @lc app=leetcode id=684 lang=cpp
 *
 * [684] Redundant Connection
 *
 * https://leetcode.com/problems/redundant-connection/description/
 *
 * algorithms
 * Medium (62.31%)
 * Likes:    5292
 * Dislikes: 355
 * Total Accepted:    275.9K
 * Total Submissions: 442.5K
 * Testcase Example:  '[[1,2],[1,3],[2,3]]'
 *
 * In this problem, a tree is an undirected graph that is connected and has no
 * cycles.
 * 
 * You are given a graph that started as a tree with n nodes labeled from 1 to
 * n, with one additional edge added. The added edge has two different vertices
 * chosen from 1 to n, and was not an edge that already existed. The graph is
 * represented as an array edges of length n where edges[i] = [ai, bi]
 * indicates that there is an edge between nodes ai and bi in the graph.
 * 
 * Return an edge that can be removed so that the resulting graph is a tree of
 * n nodes. If there are multiple answers, return the answer that occurs last
 * in the input.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: edges = [[1,2],[1,3],[2,3]]
 * Output: [2,3]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
 * Output: [1,4]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == edges.length
 * 3 <= n <= 1000
 * edges[i].length == 2
 * 1 <= ai < bi <= edges.length
 * ai != bi
 * There are no repeated edges.
 * The given graph is connected.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int>parent,sz;
    int findparent(int a){
        if(a==parent[a])return a;
        return parent[a]=findparent(parent[a]);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        parent.resize(n+1);
        iota(parent.begin(),parent.end(),0);
        sz.resize(n+1,1);
        for(auto x:edges){
            int u=x[0],v=x[1];
            int pu=findparent(u);
            int pv=findparent(v);
            if(pu==pv)return x;
            if(sz[pu]<sz[pv]){
                parent[pu]=pv;
                sz[pv]+=sz[pu];
            }
            else{
                parent[pv]=pu;
                sz[pu]+=sz[pv];
            }
        }
        return {};
    }
};
// @lc code=end

