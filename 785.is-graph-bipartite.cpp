/*
 * @lc app=leetcode id=785 lang=cpp
 *
 * [785] Is Graph Bipartite?
 *
 * https://leetcode.com/problems/is-graph-bipartite/description/
 *
 * algorithms
 * Medium (53.26%)
 * Likes:    6563
 * Dislikes: 306
 * Total Accepted:    411.6K
 * Total Submissions: 769.1K
 * Testcase Example:  '[[1,2,3],[0,2],[0,1,3],[0,2]]'
 *
 * There is an undirected graph with n nodes, where each node is numbered
 * between 0 and n - 1. You are given a 2D array graph, where graph[u] is an
 * array of nodes that node u is adjacent to. More formally, for each v in
 * graph[u], there is an undirected edge between node u and node v. The graph
 * has the following properties:
 *
 *
 * There are no self-edges (graph[u] does not contain u).
 * There are no parallel edges (graph[u] does not contain duplicate
 * values).
 * If v is in graph[u], then u is in graph[v] (the graph is undirected).
 * The graph may not be connected, meaning there may be two nodes u and v such
 * that there is no path between them.
 *
 *
 * A graph is bipartite if the nodes can be partitioned into two independent
 * sets A and B such that every edge in the graph connects a node in set A and
 * a node in set B.
 *
 * Return true if and only if it is bipartite.
 *
 *
 * Example 1:
 *
 *
 * Input: graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
 * Output: false
 * Explanation: There is no way to partition the nodes into two independent
 * sets such that every edge connects a node in one and a node in the other.
 *
 * Example 2:
 *
 *
 * Input: graph = [[1,3],[0,2],[1,3],[0,2]]
 * Output: true
 * Explanation: We can partition the nodes into two sets: {0, 2} and {1, 3}.
 *
 *
 * Constraints:
 *
 *
 * graph.length == n
 * 1 <= n <= 100
 * 0 <= graph[u].length < n
 * 0 <= graph[u][i] <= n - 1
 * graph[u] does not contain u.
 * All the values of graph[u] are unique.
 * If graph[u] contains v, then graph[v] contains u.
 *
 *
 */

// @lc code=start
class Solution
{
public:
  bool dfs(int src, vector<int> &color, vector<vector<int>> &graph)
  {

    for (auto it : graph[src])
    {
      if (color[it] == 0)
      {
        color[it] = -color[src];
        if(dfs(it, color, graph)==false)return false;
      }
      else if (color[src] == color[it])
      {
        return false;
      }
    }
    return true;
  }

  // dfs
  bool isBipartite(vector<vector<int>> &graph)
  {
    int n = graph.size();
    vector<int> color(n);
    for (int i = 0; i < n; i++)
    {
      if (color[i])
        continue;
      color[i] = 1;
      if (dfs(i, color, graph) == false)
        return false;
    }
    return true;
  }

  // bfs
  //  bool isBipartite(vector<vector<int>> &graph)
  //  {

  //   // return true;
  //   int n = graph.size();

  //   // color grapgh with two colors 1,-1
  //   vector<int> color(n);

  //   for (int i = 0; i < n; i++)
  //   {
  //     // if its already colored, skip the vertex
  //     if (color[i])
  //       continue;

  //     // color the current vertex with 1
  //     color[i] = 1;
  //     queue<int> lola;
  //     lola.push(i);
  //     while(!lola.empty())
  //     {
  //       int vertex = lola.front();
  //       lola.pop();
  //       for (auto neighbour : graph[vertex])
  //       {
  //         if (!color[neighbour])
  //         {
  //           color[neighbour] = -color[vertex];
  //           lola.push(neighbour);
  //         }
  //         else if (color[neighbour] == color[vertex])
  //         {
  //           return false;
  //         }
  //       }
  //     }
  //   }
  //   return true;
  // }
};
// @lc code=end
