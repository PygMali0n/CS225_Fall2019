#include "Graph.h"
#include "Edge.h"
#include "Vertex.h"

#include <string>
#include <iostream>

/**
* @return The number of vertices in the Graph
*/
template <class V, class E>
unsigned int Graph<V,E>::numVertices() const {
  // TODO: Part 2
  return vertexMap.size();
}


/**
* The degree of the vertex. For directed: Sum of in-degree and out-degree
* @return Returns the degree of a given vertex.
* @param v Given vertex to return degree.
*/
template <class V, class E>
unsigned int Graph<V,E>::degree(const V & v) const {
  // TODO: Part 2
  string key = v.key();
  auto it = adjList.find(key);

  return it->second.size();
}


/**
* Inserts a Vertex into the Graph.
* @param key The key of the Vertex to insert
* @return The inserted Vertex
*/
template <class V, class E>
V & Graph<V,E>::insertVertex(std::string key) {
  // TODO: Part 2
  V & v = *(new V(key));
  vertexMap.emplace(key, v);
  adjList[key] = std::list<edgeListIter>();
  return v;
}


/**
* Removes a given Vertex
* @param v The Vertex to remove
*/
template <class V, class E>
void Graph<V,E>::removeVertex(const std::string & key) {
  // TODO: Part 2
  std::list<std::reference_wrapper<E>> edges = incidentEdges(key);
  for (auto it = edges.begin(); it != edges.end(); ++it) {
    removeEdge(it->get().source(), it->get().dest());
  }
  adjList.erase(key);
  vertexMap.erase(key);
}


/**
* Inserts an Edge into the Graph.
* @param v1 The source Vertex
* @param v2 The destination Vertex
* @return The inserted Edge
*/
template <class V, class E>
E & Graph<V,E>::insertEdge(const V & v1, const V & v2) {
  // TODO: Part 2
  E & e = *(new E(v1, v2));
  edgeList.push_front(e);
  edgeListIter lit = edgeList.begin();
  string key1 = v1.key();
  string key2 = v2.key();
  auto it1 = adjList.find(key1);
  auto it2 = adjList.find(key2);
  it1->second.push_back(lit);
  it2->second.push_back(lit);




  return e;
}


/**
* Removes an Edge from the Graph. Consider both the undirected and directed cases.
* min(degree(key1), degree(key2))
* @param key1 The key of the source Vertex
* @param key2 The key of the destination Vertex
*/
template <class V, class E>
void Graph<V,E>::removeEdge(const std::string key1, const std::string key2) {
  // TODO: Part 2
  edgeListIter tor;
  for (auto it = edgeList.begin(); it != edgeList.end(); ++it) {
    E e = it->get();
    if (e.source() == key1 && e.dest() == key2) {
      tor = it;

      auto iter2 = adjList[key1].begin();
      while (*iter2 != it) {
        iter2++;
      }
      adjList[key1].erase(iter2);
      iter2 = adjList[key2].begin();
      while (*iter2 != it) {
        iter2++;
      }
      adjList[key2].erase(iter2);
    }
  }
  edgeList.erase(tor);
}


/**
* Removes an Edge from the Graph given by the location of the given iterator into the edge list.
* @param it An iterator at the location of the Edge that
* you would like to remove
*/
template <class V, class E>
void Graph<V,E>::removeEdge(const edgeListIter & it) {
  // TODO: Part 2
  edgeList.erase(it);
}


/**
* Return the list of incident edges from a given vertex.
* For the directed case, consider all edges that has the vertex as either a source or destination.
* @param key The key of the given vertex
* @return The list edges (by reference) that are adjacent to the given vertex
*/
template <class V, class E>
const std::list<std::reference_wrapper<E>> Graph<V,E>::incidentEdges(const std::string key) const {
  // TODO: Part 2
  std::list<edgeListIter> edgelist = adjList.find(key)->second;
  std::list<std::reference_wrapper<E>> edges;
  for (edgeListIter & e : edgelist) {
    edges.push_front(*e);
  }
  return edges;
}


/**
* Return whether the two vertices are adjacent to one another. Consider both the undirected and directed cases.
* When the graph is directed, v1 and v2 are only adjacent if there is an edge from v1 to v2.
* @param key1 The key of the source Vertex
* @param key2 The key of the destination Vertex
* @return True if v1 is adjacent to v2, False otherwise
*/
template <class V, class E>
bool Graph<V,E>::isAdjacent(const std::string key1, const std::string key2) const {
  // TODO: Part 2
  for (const E_byRef & e : edgeList) {
    if (e.get().source() == key1 && e.get().dest() == key2) {
      return true;
    }
  }
  return false;
}
