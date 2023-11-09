#include <iostream>
#include <sys/wait.h>
#include <vector>

#define NUM_VERT 10
#define GRAPH std::vector<std::vector<int>>

/* A graph will look something like this
 *
 *    0 1 2 3 4 5
 * 0 [0 1 0 1 0 1]
 * 1 [0 1 1 0 0 0]
 * 2 [0 1 0 0 1 0]
 * 3 [0 1 0 1 0 1]
 * 4 [0 1 0 1 1 1]
 * 5 [0 1 1 0 1 1]
 */

using namespace std;

void printGraph(GRAPH g) {
  cout << "  ";
  for (int i = 0; i < NUM_VERT; i++) {
    cout << " " << i;
  }
  cout << endl;

  for (int i = 0; i < NUM_VERT; i++) {
    cout << i << " [";
    for (int j = 0; j < NUM_VERT; j++) {
      cout << g.at(i).at(j) << " ";
    }
    cout << "]" << endl;
  }
}

int main() {
  GRAPH result(NUM_VERT);
  for (int i = 0; i < NUM_VERT; i++) {
    for (int j = 0; j < NUM_VERT; j++) {
      result.at(i).push_back(rand() % 2);
    }
  }
  printGraph(result);
  return 0;
}
