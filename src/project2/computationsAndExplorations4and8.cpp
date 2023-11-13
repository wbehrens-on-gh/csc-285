/**
 *
 */
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

#define NUM_VERT 20
#define GRAPH std::vector<std::vector<uint>>

using namespace std;

/**
 * - Each column in the matrix can have at most n-1 connections
 * - If a connects to b then b is connected to a
 * - A simple graph can be connected or disconnected
 *
 * source: mathworld.wolfram.com/simplegraph.html
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
  for (size_t row = 0; row < NUM_VERT; row++) {
    cout << " " << row;
  }
  cout << endl;

  for (size_t row = 0; row < NUM_VERT; row++) {
    cout << row << " [";
    for (size_t col = 0; col < NUM_VERT; col++) {
      cout << g[row][col] << " ";
    }
    cout << "]" << endl;
  }
}

/**
 * Generate at random a simple graph with n vertices.
 */
GRAPH generateGraph(uint n) {
  srand(time(0)); // Reset random-ness seed
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

bool isConnected(GRAPH g) {
  // if the sum of any column is 0 then it's not connected
  int sum;
  for (size_t row = 0; row < NUM_VERT; row++) {
    sum = 0;
    for (size_t col = 0; col < NUM_VERT; col++) {
      if (g[row][col] != 0) {
        sum++;
      }
    }
    if (sum == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  GRAPH graph = generateGraph(NUM_VERT);
  printGraph(graph);
  cout << "Is connected?: " << isConnected(graph) << endl;
  return 0;
}
