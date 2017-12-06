#!/bin/bash

make >/dev/null || echo "Compilation failed"

./life <<< "3 3 3 0 1 0 0 1 0 0 1 0"
