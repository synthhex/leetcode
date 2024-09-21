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
    int findClosestNumber(vector<int>& nums) {
        int closest_ind = 0;
        
        vector<int> dist(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < 0)
                dist[i] = -nums[i];
            else
                dist[i] = nums[i];
            if (dist[closest_ind] > dist[i])
                closest_ind = i;
            else if (dist[closest_ind] == dist[i] && nums[closest_ind] < nums[i])
                closest_ind = i;
                
        }

        return nums[closest_ind];
    }
};
