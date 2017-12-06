#!/bin/bash

make >/dev/null || echo "Compilation failed"

./life <<< "1 2 2 1 1 1 1"
