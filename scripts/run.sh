#!/bin/bash

clang++ ../src/*.cpp \
-I ../include \
-o ../dist/main && ../dist/main