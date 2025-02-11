/**
 * @file NimLearner.cpp
 * CS 225: Data Structures
 */

#include "NimLearner.h"
#include <ctime>


/**
 * Constructor to create a game of Nim with `startingTokens` starting tokens.
 *
 * This function creates a graph, `g_` representing all of the states of a
 * game of Nim with vertex labels "p#-X", where:
 * - # is the current player's turn; p1 for Player 1, p2 for Player2
 * - X is the tokens remaining at the start of a player's turn
 *
 * For example:
 *   "p1-4" is Player 1's turn with four (4) tokens remaining
 *   "p2-8" is Player 2's turn with eight (8) tokens remaining
 *
 * All legal moves between states are created as edges with initial weights
 * of 0.
 *
 * @param startingTokens The number of starting tokens in the game of Nim.
 */
NimLearner::NimLearner(unsigned startingTokens) : g_(true, true) {
    /* Your code goes here! */
    startingVertex_ = "p1-" + std::to_string(startingTokens);
    for (unsigned i = 0; i <= startingTokens; i++) {
      Vertex v1 = "p1-" + std::to_string(i);
      Vertex v2 = "p2-" + std::to_string(i);
      g_.insertVertex(v1);
      g_.insertVertex(v2);
      if (i == 0) {
        continue;
      } else if (i == 1) {
        int j = i - 1;
        Vertex v12 = "p2-" + std::to_string(j);
        Vertex v21 = "p1-" + std::to_string(j);
        g_.insertEdge(v1, v12);
        g_.setEdgeWeight(v1, v12,0);
        g_.insertEdge(v2, v21);
        g_.setEdgeWeight(v2, v21,0);
      } else {
        int j = i-1;
        int k = i-2;
        Vertex v12 = "p2-" + std::to_string(j);
        Vertex v21 = "p1-" + std::to_string(j);
        g_.insertEdge(v1, v12);
        g_.setEdgeWeight(v1, v12,0);
        g_.insertEdge(v2, v21);
        g_.setEdgeWeight(v2, v21,0);
        Vertex v122 = "p2-" + std::to_string(k);
        Vertex v212 = "p1-" + std::to_string(k);
        g_.insertEdge(v1, v122);
        g_.setEdgeWeight(v1, v122,0);
        g_.insertEdge(v2, v212);
        g_.setEdgeWeight(v2, v212,0);
      }
    }
}

/**
 * Plays a random game of Nim, returning the path through the state graph
 * as a vector of `Edge` classes.  The `origin` of the first `Edge` must be
 * the vertex with the label "p1-#", where # is the number of starting
 * tokens.  (For example, in a 10 token game, result[0].origin must be the
 * vertex "p1-10".)
 *
 * @returns A random path through the state space graph.
 */
std::vector<Edge> NimLearner::playRandomGame() const {
  vector<Edge> path;
  Vertex current = startingVertex_;
  Vertex tmpv;
  /* Your code goes here! */
  while (current != "p1-0" && current != "p2-0") {
    vector<Vertex> adj = g_.getAdjacent(current);
    tmpv = adj[rand() % adj.size()];
    path.push_back(g_.getEdge(current, tmpv));
    current = tmpv;
  }
  return path;
}

/*
 * Updates the edge weights on the graph based on a path through the state
 * tree.
 *
 * If the `path` has Player 1 winning (eg: the last vertex in the path goes
 * to Player 2 with no tokens remaining, or "p2-0", meaning that Player 1
 * took the last token), then all choices made by Player 1 (edges where
 * Player 1 is the source vertex) are rewarded by increasing the edge weight
 * by 1 and all choices made by Player 2 are punished by changing the edge
 * weight by -1.
 *
 * Likewise, if the `path` has Player 2 winning, Player 2 choices are
 * rewarded and Player 1 choices are punished.
 *
 * @param path A path through the a game of Nim to learn.
 */
void NimLearner::updateEdgeWeights(const std::vector<Edge> & path) {
 /* Your code goes here! */
 Edge lastedge = path[path.size()-1];
 Vertex lastnode = lastedge.dest;
 if (lastnode == "p2-0") {
   //player1 wins
   for (auto it = path.begin(); it != path.end(); ++it) {
     Vertex s = it->source;
     Vertex d = it->dest;
     int weight = g_.getEdgeWeight(s,d);
     if (s.substr(1,1) == "1") {
       g_.setEdgeWeight(s,d,weight + 1);
     } else {
       g_.setEdgeWeight(s,d,weight - 1);
     }
   }
 } else if (lastnode == "p1-0"){
   for (auto it = path.begin(); it != path.end(); ++it) {
     Vertex s = it->source;
     Vertex d = it->dest;
     int weight = g_.getEdgeWeight(s,d);
     if (s.substr(1,1) == "1") {
       g_.setEdgeWeight(s,d,weight - 1);
     } else {
       g_.setEdgeWeight(s,d,weight + 1);
     }
   }
 }
}

/**
 * Label the edges as "WIN" or "LOSE" based on a threshold.
 */
void NimLearner::labelEdgesFromThreshold(int threshold) {
  for (const Vertex & v : g_.getVertices()) {
    for (const Vertex & w : g_.getAdjacent(v)) {
      int weight = g_.getEdgeWeight(v, w);

      // Label all edges with positve weights as "WINPATH"
      if (weight > threshold)           { g_.setEdgeLabel(v, w, "WIN"); }
      else if (weight < -1 * threshold) { g_.setEdgeLabel(v, w, "LOSE"); }
    }
  }
}

/**
 * Returns a constant reference to the state space graph.
 *
 * @returns A constant reference to the state space graph.
 */
const Graph & NimLearner::getGraph() const {
  return g_;
}
