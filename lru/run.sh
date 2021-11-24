#!/bin/bash

g++ newlru.cpp -o lru 
./lru
python3 lrugraph.py
