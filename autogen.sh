#!/bin/sh

autoreconf --force --install --warnings=all

./configure $args "$@"
make clean
