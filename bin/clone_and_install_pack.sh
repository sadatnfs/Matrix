#!/bin/bash
set -e # Exit with nonzero exit code if anything fails

if [ ! -f ~/.R/Makevars ]; then
    mkdir -p ~/.R
    echo "CXX = g++ -w -m64 -g -fno-gnu-unique" > ~/.R/Makevars
fi


## Clone
# git clone -b develop https://github.com/sadatnfs/Matrix.git

## Tar it
ls -altr
tar czf Matrix_2.tar.gz ../Matrix


## Install 
R CMD INSTALL Matrix_2.tar.gz