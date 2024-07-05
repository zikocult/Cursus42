#!/bin/bash

find $PWD -iname '*.out' -print 2>/dev/null -exec rm -f {} \;
find $PWD -iname '*.swp' -print 2>/dev/null -exec rm -f {} \;
find $PWD -iname '.DS_Store' -print 2>/dev/null -exec rm -f {} \;
find $PWD -iname '*.gch' -print 2>/dev/null -exec rm -f {} \;
