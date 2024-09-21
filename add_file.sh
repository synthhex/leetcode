#!/bin/bash

# Check if a LeetCode URL was provided
if [ -z "$1" ]; then
  echo "Usage: $0 <leetcode-url>"
  exit 1
fi

# Extract problem title from the provided URL
problem_title=$(echo "$1" | sed -E 's|.*/problems/([^/]+)/.*|\1|')

# The parameters for the GraphQL API
problem_query="\n    query questionTitle(\$titleSlug: String!) {\n  question(titleSlug: \$titleSlug) {\n    questionId\n    questionFrontendId\n    title\n    titleSlug\n    isPaidOnly\n    difficulty\n    likes\n    dislikes\n    categoryTitle\n  }\n}\n    "
operation_name="questionTitle"
variables="{\"titleSlug\":\"$problem_title\"}"

# Send the request to the GraphQL API
response=$(curl -s 'https://leetcode.com/graphql' \
  -H 'content-type: application/json' \
  --data-raw "{\"query\":\"$problem_query\",\"operationName\":\"$operation_name\",\"variables\":$variables}")

# Extract the problem title from the response
problem_title=$(echo "$response" | jq -r '.data.question.titleSlug')
problem_number=$(echo "$response" | jq -r '.data.question.questionFrontendId')

# Check if both the problem number and title are available
if [ -z "$problem_title" ] || [ -z "$problem_number" ]; then
  echo "Failed to extract the problem title or number from the provided URL."
  exit 1
fi

# The parameters for the GraphQL API
skeleton_query="\n    query questionEditorData(\$titleSlug: String!) {\n  question(titleSlug: \$titleSlug) {\n    questionId\n    questionFrontendId\n    codeSnippets {\n      lang\n      langSlug\n      code\n    }\n    envInfo\n    enableRunCode\n    hasFrontendPreview\n    frontendPreviews\n  }\n}\n    "
operation_name="questionEditorData"
variables="{\"titleSlug\":\"$problem_title\"}"

# Send the request to the GraphQL API
response=$(curl -s 'https://leetcode.com/graphql' \
  -H 'content-type: application/json' \
  --data-raw "{\"query\":\"$skeleton_query\",\"operationName\":\"$operation_name\",\"variables\":$variables}")

# Extract the C++ code skeleton from the response
skeleton_code="#include <iostream>     // Input/output stream
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

$(echo "$response" | jq -r '.data.question.codeSnippets[] | select(.langSlug == "cpp") | .code')"

# The folder name
folder_name="$problem_number-$problem_title"

# Create the folder
mkdir -p "$problem_number-$problem_title"

# Fall back to a basic C++ template if the skeleton isn't found
if [ -z "$skeleton_code" ]; then
  skeleton_code="
// C++ Solution Template
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

int main() {
    // Your code goes here
    return 0;
}
"
fi

# Create the main.cpp file with the extracted code
solution_file="$folder_name/main.cpp"
echo "$skeleton_code" > "$solution_file"

# Inform the user
echo "Created folder: $folder_name"
echo "Created file: $solution_file"