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
    void rotate(vector<vector<int>>& matrix) {
        // Mirror rows
        for (int i = 0; i < matrix.size() / 2; ++i)
            swap(matrix[i], matrix[matrix.size() - 1 - i]);
        
        // Transpose matrix
        for (int i = 0; i < matrix.size() - 1; ++i) {
            for (int j = i + 1; j < matrix.size(); ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};