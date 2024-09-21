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
    int romanToInt(string s) {
        int sum = 0;
        s += '!';

        for (int i = 0; i < s.length() - 1; ++i) {
            if (s[i] == 'I') {
                if (s[i + 1] == 'V') {
                    sum += 4;
                    ++i;
                } else if (s[i + 1] == 'X') {
                    sum += 9;
                    ++i;
                } else {
                    sum += 1;
                }
            } else if (s[i] == 'V') {
                sum += 5;
            } else if (s[i] == 'X') {
                if (s[i + 1] == 'L') {
                    sum += 40;
                    ++i;
                } else if (s[i + 1] == 'C') {
                    sum += 90;
                    ++i;
                } else {
                    sum += 10;
                }
            } else if (s[i] == 'L') {
                sum += 50;
            } else if (s[i] == 'C') {
                if (s[i + 1] == 'D') {
                    sum += 400;
                    ++i;
                } else if (s[i + 1] == 'M') {
                    sum += 900;
                    ++i;
                } else {
                    sum += 100;
                }
            } else if (s[i] == 'D') {
                sum += 500;
            } else {
                sum += 1000;
            }
        }

        return sum;
    }
};