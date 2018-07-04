#!/bin/bash
set -e # Exit with nonzero exit code if anything fails

# wget https://cran.r-project.org/src/contrib/Archive/roxygen2/roxygen2_6.0.0.tar.gz
Rscript -e 'pkg <- c("methods", "graphics", "grid", "stats", "utils", "lattice"); if(!all(pkg%in%installed.packages()))install.packages(pkg)'

