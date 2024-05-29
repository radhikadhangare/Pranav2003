#include <iostream>
#include <stack>
#include <set>
#include <tuple>
#include<vector>

using namespace std;

bool dfs_water_jug(int jug1_capacity, int jug2_capacity, int target) {
    set<pair<int, int>> visited;
    stack<pair<int, int>> s;
    s.push({0, 0});
    visited.insert({0, 0});

    while (!s.empty()) {
       pair<int, int> j = s.top();
        
        int jug1 = j.first;
        int jug2 = j.second;
        s.pop();

        cout << "Exploring state: (" << jug1 << ", " << jug2 << ")" << endl;

        if (jug1 == target || jug2 == target) {
            return true;
        }

        vector<pair<int, int>> next_states = {
            {jug1_capacity, jug2}, // fill jug1
            {jug1, jug2_capacity}, // fill jug2
            {0, jug2},             // empty jug1
            {jug1, 0},             // empty jug2
            {min(jug1 + jug2, jug1_capacity), jug1 + jug2 - min(jug1 + jug2, jug1_capacity)}, // pour jug2 to jug1
            {jug1 + jug2 - min(jug1 + jug2, jug2_capacity), min(jug1 + jug2, jug2_capacity)}  // pour jug1 to jug2
        };

        for (auto state : next_states) {
            if (visited.find(state) == visited.end()) {
                visited.insert(state);
                s.push(state);
            }
        }
    }

    return false;
}

int main() {
    int jug1_capacity = 2;
    int jug2_capacity = 3;
    int target = 1;
    if (dfs_water_jug(jug1_capacity, jug2_capacity, target)) {
        cout << "Solution found using DFS" << endl;
    } else {
        cout << "No solution found using DFS" << endl;
    }
    return 0;
}

