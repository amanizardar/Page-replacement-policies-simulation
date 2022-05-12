#!/bin/bash

#WSclock
g++ wsclock.cpp -o wsclock 
./wsclock

#Working Set
g++ Working_set.cpp -o working 
./working

#Aging
g++ aging.cpp -o aging 
./aging

#Clock
g++ CLOCK.cpp -o clock 
./clock

#Fifosecondchance
g++ FIFOwithSecondChance.cpp -o FIFOwithSecondChance 
./FIFOwithSecondChance


#NRU
g++ NRU.cpp -o NRU 
./NRU

#LRU
g++ lru.cpp -o lru 
./lru

#Optimal
g++ optimal.cpp -o optimal 
./optimal

#random
g++ random.cpp -o random 
./random

#fifo
g++ fifo.cpp -o fifo 
./fifo

#nfu
g++ nfu.cpp -o nfu
./nfu


#Printing Graph
python3 graph.py
python3 graph2.py

#Clearing files 
rm pagefaultdata_aging.txt
rm pagefaultdata_workingset.txt
rm pagefaultdata_wsclock.txt
rm pagefaultdata_CLOCK.txt
rm pagefaultdata_FIFOwithSecondChance.txt
rm pagefaultdata_NRU.txt
rm pagefaultdata_lru.txt
rm pagefaultdata_optimal.txt
rm pagefaultdata_random.txt
rm pagefaultdata_fifo.txt
rm pagefaultdata_nfu.txt


rm wsclock working aging clock FIFOwithSecondChance NRU lru optimal random fifo nfu

