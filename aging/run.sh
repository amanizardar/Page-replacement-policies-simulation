#!/bin/bash

g++ aging.cpp -o aging 
./aging
python3 graph.py
