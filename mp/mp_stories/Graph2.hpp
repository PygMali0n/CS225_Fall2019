#include <queue>
#include <algorithm>
#include <string>
#include <list>
#include <vector>
#include <map>

/**
 * Returns an std::list of vertex keys that creates any shortest path between `start` and `end`.
 *
 * This list MUST include the key of the `start` vertex as the first vertex in the list, the key of
 * the `end` vertex as the last element in the list, and an ordered list of all vertices that must
 * be traveled along the shortest path.
 *
 * For example, the path a -> c -> e returns a list with three elements: "a", "c", "e".
 *
 * You should use undirected edges. Hint: There are no edge weights in the Graph.
 *
 * @param start The key for the starting vertex.
 * @param end   The key for the ending vertex.
 */
template <class V, class E>
std::list<std::string> Graph<V,E>::shortestPath(const std::string start, const std::string end) {
  // TODO: Part 3
  std::list<std::string> path;
  std::queue<string> bfs;
  std::map<string, int> distance;
  std::map<string, string> pred;
  string curr;
  bfs.push(start);
  distance[start] = 0;

  while (!bfs.empty()) {
    curr = bfs.front();
    bfs.pop();
    for (auto it = adjList[curr].begin(); it != adjList[curr].end(); ++it) {
      string neighbor = (*it)->get().dest().key();
      if (neighbor == curr) {
        neighbor = (*it)->get().source().key();
      }
      if (pred.find(neighbor) == pred.end()) {
        bfs.push(neighbor);
        pred[neighbor] = curr;
        distance[neighbor] = distance[pred[neighbor]] + 1;
      }
    }
  }

  curr = end;
  while (curr != start) {
    path.push_front(curr);
    curr = pred[curr];
  }
  path.push_front(curr);



  return path;
}
