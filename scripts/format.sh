#!/bin/bash

# Format all .h and .cpp files in the project
find . -name '*.h' -o -name '*.cpp' | xargs clang-format -i
