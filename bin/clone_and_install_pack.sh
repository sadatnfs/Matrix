#!/bin/bash
set -e # Exit with nonzero exit code if anything fails

if [ ! -f ~/.R/Makevars ]; then
    mkdir -p ~/.R
    echo "CXX = g++ -w -m64 -g -fno-gnu-unique" > ~/.R/Makevars
fi


## Tar it
ls -altr
cd ..
tar czf Matrix_2.tar.gz Matrix

## Install 
R CMD INSTALL Matrix_2.tar.gz
