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
    string mergeAlternately(string word1, string word2) {
        string res = "";
        int m = word1.length();
        int n = word2.length();

        for (int i = 0; i < max(m, n); ++i) {
            if (i < m)
                res += word1[i];
            if (i < n)
                res += word2[i];
        }

        return res;
    }
};
