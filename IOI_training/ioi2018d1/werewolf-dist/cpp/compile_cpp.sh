#!/bin/bash

TASK=werewolf

g++ -std=gnu++14 -DDEBUG -O2 -static -o ${TASK} grader.cpp ${TASK}.cpp
