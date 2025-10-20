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
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ranges;

        if (nums.size() == 0)
            return ranges;
        if (nums.size() == 1) {
            ranges.push_back(to_string(nums[0]));
            return ranges; 
        }
        int first = nums[0];
        int last = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (last + 1 == nums[i])
                last = nums[i];
            else {
                ranges.push_back(first == last ? to_string(first) : to_string(first) + "->" + to_string(last));
                first = nums[i];
                last = nums[i];
            } 
        }

        ranges.push_back(first == last ? to_string(first) : to_string(first) + "->" + to_string(last));

        return ranges;
    }
};