#!/bin/bash
set -e # Exit with nonzero exit code if anything fails


## Test to see if data.table is picked up
R -e "library(data.table); test.data.table()"

for file in tests/*.R
do
    printf "Running test file: ${file}"
    Rscript -e "source(\"$file\")"
done

