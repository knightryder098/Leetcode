/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 *
 * https://leetcode.com/problems/course-schedule/description/
 *
 * algorithms
 * Medium (45.43%)
 * Likes:    13357
 * Dislikes: 534
 * Total Accepted:    1.2M
 * Total Submissions: 2.6M
 * Testcase Example:  '2\n[[1,0]]'
 *
 * There are a total of numCourses courses you have to take, labeled from 0 to
 * numCourses - 1. You are given an array prerequisites where prerequisites[i]
 * = [ai, bi] indicates that you must take course bi first if you want to take
 * course ai.
 * 
 * 
 * For example, the pair [0, 1], indicates that to take course 0 you have to
 * first take course 1.
 * 
 * 
 * Return true if you can finish all courses. Otherwise, return false.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: numCourses = 2, prerequisites = [[1,0]]
 * Output: true
 * Explanation: There are a total of 2 courses to take. 
 * To take course 1 you should have finished course 0. So it is possible.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
 * Output: false
 * Explanation: There are a total of 2 courses to take. 
 * To take course 1 you should have finished course 0, and to take course 0 you
 * should also have finished course 1. So it is impossible.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= numCourses <= 2000
 * 0 <= prerequisites.length <= 5000
 * prerequisites[i].length == 2
 * 0 <= ai, bi < numCourses
 * All the pairs prerequisites[i] are unique.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool cycle(int src,vector<vector<int>>&graph,vector<bool>&visited,vector<bool>&path){
        visited[src]=true;
        path[src]=true;
        for(auto it:graph[src]){
            if(!visited[it]){
                if(cycle(it,graph,visited,path))return true;
            }
            else if(path[it]==true)return true;
        }
        path[src]=false;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>>graph(n,vector<int>());
        for(auto x:pre){
            graph[x[0]].push_back(x[1]);
        }

        vector<bool>visited(n,false),path(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                if(cycle(i,graph,visited,path))return false;
            }
        }
        return true;
    }
};
// @lc code=end

