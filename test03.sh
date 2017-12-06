#!/bin/bash

make >/dev/null || echo "Compilation failed"

TOAD="3 6 6 "\
"0 0 0 0 0 0 "\
"0 0 0 0 0 0 "\
"0 0 1 1 1 0 "\
"0 1 1 1 0 0 "\
"0 0 0 0 0 0 "\
"0 0 0 0 0 0"

./life <<< $TOAD
