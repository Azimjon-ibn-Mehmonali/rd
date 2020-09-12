#!/bin/bash

g++-9 -Wall -lm -static -DEVAL -o split -O2 split.cpp grader.cpp -std=c++17