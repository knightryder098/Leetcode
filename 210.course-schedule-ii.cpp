/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 *
 * https://leetcode.com/problems/course-schedule-ii/description/
 *
 * algorithms
 * Medium (48.61%)
 * Likes:    9149
 * Dislikes: 299
 * Total Accepted:    817.4K
 * Total Submissions: 1.7M
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
 * Return the ordering of courses you should take to finish all courses. If
 * there are many valid answers, return any of them. If it is impossible to
 * finish all courses, return an empty array.
 *
 *
 * Example 1:
 *
 *
 * Input: numCourses = 2, prerequisites = [[1,0]]
 * Output: [0,1]
 * Explanation: There are a total of 2 courses to take. To take course 1 you
 * should have finished course 0. So the correct course order is [0,1].
 *
 *
 * Example 2:
 *
 *
 * Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
 * Output: [0,2,1,3]
 * Explanation: There are a total of 4 courses to take. To take course 3 you
 * should have finished both courses 1 and 2. Both courses 1 and 2 should be
 * taken after you finished course 0.
 * So one correct course order is [0,1,2,3]. Another correct ordering is
 * [0,2,1,3].
 *
 *
 * Example 3:
 *
 *
 * Input: numCourses = 1, prerequisites = []
 * Output: [0]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= numCourses <= 2000
 * 0 <= prerequisites.length <= numCourses * (numCourses - 1)
 * prerequisites[i].length == 2
 * 0 <= ai, bi < numCourses
 * ai != bi
 * All the pairs [ai, bi] are distinct.
 *
 *
 */

// @lc code=start
class Solution
{
public:
    bool dfs(int src, vector<vector<int>> &graph, stack<int> &xxx, vector<bool> &visited, vector<bool> &path)
    {
        visited[src] = path[src] = true;
        for (auto it : graph[src])
        {
            if (!visited[it])
            {
                if (dfs(it, graph, xxx, visited, path))
                    return true;
            }
            else if (path[it])
                return true;
        }
        path[src] = false;
        xxx.push(src);
        return false;
    }

    vector<int> findOrder(int n, vector<vector<int>> &pre)
    {
        vector<int> ans;
        // stack<int>xxx;
        vector<vector<int>> graph(n, vector<int>());
        vector<int> indegree(n, 0);
        for (auto x : pre)
        {
            graph[x[0]].push_back(x[1]);
            indegree[x[1]]++;
        }

        queue<int> lola;
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
                lola.push(i);
        }
        while (!lola.empty())
        {
            int vertex = lola.front();
            ans.push_back(vertex);
            lola.pop();
            for (auto it : graph[vertex])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                {
                    lola.push(it);
                }
                else if (indegree[it] < 0)
                    return {};
            }
        }

        if (count(begin(indegree), end(indegree), 0) != n)
            return {};

            
        // vector<bool>visited(n,false),path(n,false);
        // for(int i=0;i<n;i++){
        //     if(!visited[i]){
        //         if(dfs(i,graph,xxx,visited,path))return {};
        //         // dfs2(i,graph,visited,xxx);
        //     }
        // }

        // while(!xxx.empty()){
        //     ans.push_back(xxx.top());
        //     xxx.pop();
        // }
        reverse(begin(ans), end(ans));
        return ans;
    }
};
// @lc code=end
