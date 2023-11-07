#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

#define GRAPH std::vector<std::tuple<int, int>>

bool is_bipartite(GRAPH g) {
    vector<int> team1;
    vector<int> team2;

    for (int i=0; i<=g.size(); i++){
        if(){
          team1.push_back(get<0>(line));
        } else{
            team2.push_back(get<1>(line));
        }
    }

    return true;
}

int main() {
    is_bipartite({{0,1}
    });
}

