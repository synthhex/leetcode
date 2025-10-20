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
    string longestCommonPrefix(vector<string>& strs) {
        int min_len = strs[0].length();
        int min_ind = 0;
        for (int i = 0; i < strs.size(); ++i) {
            int len = strs[i].length();
            if (len < min_len) {
                min_len = len;
                min_ind = i;
            }
        }

        for (int j = 0; j < min_len; j++) {
            bitset<8> total(strs[0][j]);
            for (int i = 1; i < strs.size(); ++i) {
                bitset<8> ch(strs[i][j]);
                if (total != ch)
                    return strs[min_ind].substr(0, j);
            }
        }

        return strs[min_ind];
    }
};