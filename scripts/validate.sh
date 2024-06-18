#!/bin/sh

# Format the code
./scripts/format.sh

# Build the project
./scripts/build.sh
BUILD_RESULT=$?

# Run tests
./scripts/test.sh
TEST_RESULT=$?

# Check if all checks were successful
if [ $BUILD_RESULT -ne 0 ] || [ $TEST_RESULT -ne 0 ]; then
    echo "Pre-commit hook failed. Fix the errors before committing."
    exit 1
fi

echo "Pre-commit hook passed. Proceeding with commit."
exit 0
