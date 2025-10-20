#include <iostream>     // Input/output stream
#include <vector>       // Dynamic array (vector)
#include <algorithm>    // Algorithms like sort, max, min, etc.
#include <string>       // String class
#include <cmath>        // Mathematical functions
#include <map>          // Associative containers (map)
#include <set>          // Set container
#include <unordered_map>// Unordered associative containers (unordered_map)
#include <unordered_set>// Unordered associative containers (unordered_set)
#include <queue>        // Queue, priority_queue
#include <stack>        // Stack container
#include <deque>        // Double-ended queue
#include <climits>      // Limits of integral types
#include <cstring>      // C-style string manipulation
#include <cassert>      // Assertion for debugging
#include <bitset>       // Bit manipulation
#include <tuple>        // Tuple for storing multiple values
#include <numeric>      // Numeric operations like accumulate
#include <chrono>       // Timing utilities
#include <random>       // Random number generation

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int w = matrix[0].size();
        int h = matrix.size();
        int size = w * h;
        vector<int> spiral(size);

        int ctr = 0;
        pair<int, int> pos = make_pair(0, 0);
        pair<int, int> vel = make_pair(1, 0);
        pair<int, int> wall_x = make_pair(0, w - 1);
        pair<int, int> wall_y = make_pair(1, h - 1);

        while (ctr < size) {
            // cout << format("Pos: {},{} with Walls: ({},{}), ({},{})", pos.first, pos.second, wall_x.first, wall_x.second, wall_y.first, wall_y.second) << endl;
            spiral[ctr++] = matrix[pos.second][pos.first];

            if (pos.first == wall_x.first && vel.first == -1) {
                ++ wall_x.first;
                vel.first = 0;
                vel.second = -1;
            }

            if (pos.first == wall_x.second && vel.first == 1) {
                -- wall_x.second;
                vel.first = 0;
                vel.second = 1;
            }

            if (pos.second == wall_y.first && vel.second == -1) {
                ++ wall_y.first;
                vel.first = 1;
                vel.second = 0;
            }

            if (pos.second == wall_y.second && vel.second == 1) {
                -- wall_y.second;
                vel.first = -1;
                vel.second = 0;
            }

            pos.first += vel.first;
            pos.second += vel.second;
        }

        return spiral;
    }
};