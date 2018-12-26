#!/bin/bash
set -e # Exit with nonzero exit code if anything fails

for file in tests/*.R
do
    printf "Running test file: ${file}"
    Rscript -e "source(\"$file\")"
done

