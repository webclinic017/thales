#!/bin/bash

# Navigate to the project root directory
cd "$(dirname "$0")/.."

# Find all .h and .cpp files and run clang-format on them
find . -name '*.h' -o -name '*.cpp' | xargs clang-format -i
