/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Number of Provinces
 *
 * https://leetcode.com/problems/number-of-provinces/description/
 *
 * algorithms
 * Medium (63.91%)
 * Likes:    7618
 * Dislikes: 292
 * Total Accepted:    629.4K
 * Total Submissions: 983.9K
 * Testcase Example:  '[[1,1,0],[1,1,0],[0,0,1]]'
 *
 * There are n cities. Some of them are connected, while some are not. If city
 * a is connected directly with city b, and city b is connected directly with
 * city c, then city a is connected indirectly with city c.
 * 
 * A province is a group of directly or indirectly connected cities and no
 * other cities outside of the group.
 * 
 * You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the
 * i^th city and the j^th city are directly connected, and isConnected[i][j] =
 * 0 otherwise.
 * 
 * Return the total number of provinces.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
 * Output: 3
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 200
 * n == isConnected.length
 * n == isConnected[i].length
 * isConnected[i][j] is 1 or 0.
 * isConnected[i][i] == 1
 * isConnected[i][j] == isConnected[j][i]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int>parent,size;
    int findparent(int a){
        if(a==parent[a])return a;
        return parent[a]=findparent(parent[a]);
    }

    void joinij(int a,int b){
        int pa=findparent(a);
        int pb=findparent(b);
        if(pa==pb)return;
        if(size[pa]<size[pb]){
            parent[pa]=pb;
            size[pb]+=size[pa];
        }
        else{
            parent[pb]=pa;
            size[pa]+=size[pb];
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        parent.resize(n);
        iota(begin(parent),end(parent),0);
        size.resize(n,1);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j])joinij(i,j);
            }
        }

        for(int i=0;i<n;i++)parent[i]=findparent(i);
        set<int>lola(begin(parent),end(parent));
        return lola.size();
    }
};
// @lc code=end

