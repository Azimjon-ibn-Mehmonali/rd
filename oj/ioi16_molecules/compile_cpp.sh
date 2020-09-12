#!/bin/bash

problem=molecules

g++ -O2 -std=c++17 -static -o $problem grader.cpp $problem.cpp
