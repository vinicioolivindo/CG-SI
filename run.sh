#!/bin/bash
set -e

LDFLAGS_CLEAN=$(echo $NIX_LDFLAGS | sed 's/-rpath [^ ]*//g')

gcc main.c \
    animation/animation.c \
    draw/house.c \
    draw/person.c \
    draw/shapes.c \
    draw/sky.c \
    draw/smoke.c \
    draw/tree.c \
    input/keyboard.c \
    state/scene.c \
    -o dianoite $LDFLAGS_CLEAN -lGL -lGLU -lglut -lm

./dianoite
