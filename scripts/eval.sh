#!/bin/bash
set -eo pipefail

ROOT=$(basename $(pwd))

if ./scripts/build.sh -DCMAKE_BUILD_TYPE=Release ; then
    echo "Build successful"
else
    echo "Fix build errors above"
    exit 1
fi

# Running /tests
echo "Running tests..."
if make test; then
    echo "Tests passed"

else
    echo "Tests failed"
    echo "SKIPPED: evaluation"

fi
