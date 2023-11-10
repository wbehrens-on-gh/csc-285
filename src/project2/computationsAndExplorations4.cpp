#include <iostream>
#include <vector>

#define NUM_VERT 20
#define GRAPH std::vector<std::vector<uint>>

using namespace std;

/*
 * Define simple:
 * - no loops: each column in the matrix can have at most n-1 connections where
 * n is the number of vertices.
 * - no contradiction: if a point is conneted to n-1 points then all points
 * should at least be connected to 1 other point
 * - connections must agree: if a connects to b then b is connected to a
 * - A simple graph can be connected or disconnected
 *   mathworld.wolfram.com/simplegraph.html
 */

/**
 * A graph will look something like this when printed in a terminal
 *
 *    0 1 2 3 4 5
 * 0 [0 1 1 1 1 1]
 * 1 [1 0 1 1 1 1]
 * 2 [1 1 0 1 1 1]
 * 3 [1 1 1 0 1 1]
 * 4 [1 1 1 1 0 1]
 * 5 [1 1 1 1 1 0]
 */
void printGraph(GRAPH g) {
  cout << "  ";
  for (size_t i = 0; i < NUM_VERT; i++) {
    cout << " " << i;
  }
  cout << endl;

  for (size_t i = 0; i < NUM_VERT; i++) {
    cout << i << " [";
    for (size_t j = 0; j < NUM_VERT; j++) {
      cout << g[i][j] << " ";
    }
    cout << "]" << endl;
  }
}

/**
 * Generate at random a simple graph with n vertices.
 */
GRAPH generateGraph(uint n) {
  GRAPH result(n, vector<uint>(n, 0));
  for (size_t row = 0; row < NUM_VERT; row++) {
    for (size_t col = 0; col < NUM_VERT; col++) {
      uint connected = 0;
      if (row != col) { // ensure no loops
        connected = rand() % 2;
        if (connected == 1) { // undirected: (a,b) = 1 -> (b,a) = 1
          result.at(row).at(col) = connected;
        }
      }
      result[row][col] = connected;
    }
  }
  return result;
}

int main() {
  GRAPH graph = generateGraph(NUM_VERT);
  printGraph(graph);
  return 0;
}
