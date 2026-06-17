#!/bin/bash
set -e

LDFLAGS_CLEAN=$(echo $NIX_LDFLAGS | sed 's/-rpath [^ ]*//g')
gcc dianoite.c -o dianoite $LDFLAGS_CLEAN -lGL -lGLU -lglut -lm

./dianoite
