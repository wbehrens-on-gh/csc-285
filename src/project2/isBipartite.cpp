//Delaney Lentz

#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
using namespace std;

const int V = 4;

//returns true if graph G[V][V] is Bipartite, else false
bool is_BipartiteHelp(int G[][V], int src, int colorArr[])
{
    colorArr[src] = 1;

    //Create a queue of vertex numbers assigned
    queue<int> q;

    //push src to the front of queue
    q.push(src);

    // Run while there are vertices in queue
    while (!q.empty()) {
        //returns the next element in the queue
        int u = q.front();
        //removes the last item added to
        //the top of the stack
        q.pop();

        //Return false if there is a self-loop
        if (G[u][u] == 1)
            return false;

        //Find all non-colored adj vertices
        for (int v = 0; v < V; ++v) {

            //An edge from u to v exists and
            //destination v is not colored
            if (G[u][v] && colorArr[v] == -1) {

                //Assign alternate color to this
                //adj v of u
                colorArr[v] = 1 - colorArr[u];
                q.push(v);
            }

            //An edge from u to v exists and destination
            //v is colored with same color as u
            else if (G[u][v] && colorArr[v] == colorArr[u])
                return false;
        }
    }

    //all adj vertices can be colored
    //with alternate color
    return true;
}

//Returns true if G[][] is Bipartite, else false
bool isBipartite(int G[][V])
{
    //Create a color array to store colors assigned to all
    //vertices. -1 of colorArr[i] = no color assigned to i
    //1 = first color assigned
    //0 indicates second color assigned
    int colorArr[V];
    for (int i = 0; i < V; ++i)
        colorArr[i] = -1;

    //handles disconnected graph
    for (int i = 0; i < V; i++)
        if (colorArr[i] == -1)
            if (is_BipartiteHelp(G, i, colorArr) == false)
                return false;

    return true;
}

//test functions
int main()
{
    int G[][V] = { { 0, 1, 0, 1 },
                   { 1, 0, 1, 0 },
                   { 0, 1, 0, 1 },
                   { 1, 0, 1, 0 } };

    isBipartite(G) ? cout << "Yes" : cout << "No" << endl;
    cout << endl;
    return 0;
}

