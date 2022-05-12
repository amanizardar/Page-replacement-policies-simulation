import matplotlib.pyplot as plt
import numpy as np
import math






x1=[]
y1=[]
with open("pagefaultdata_wsclock.txt",'r') as f:
    Lines = f.readlines()
    for line in Lines:
        line = line.split();
        print(line)
        x1.append(int(line[0]))
        y1.append(float(line[2])/float(line[1]))


x2=[]
y2=[]
with open("pagefaultdata_workingset.txt",'r') as f:
    Lines = f.readlines()
    for line in Lines:
        line = line.split();
        print(line)
        x2.append(int(line[0]))
        y2.append(float(line[2])/float(line[1]))


x3=[]
y3=[]
with open("pagefaultdata_aging.txt",'r') as f:
    Lines = f.readlines()
    for line in Lines:
        line = line.split();
        print(line)
        x3.append(int(line[0]))
        y3.append(float(line[2])/float(line[1]))

x4=[]
y4=[]
with open("pagefaultdata_CLOCK.txt",'r') as f:
    Lines = f.readlines()
    for line in Lines:
        line = line.split();
        print(line)
        x4.append(int(line[0]))
        y4.append(float(line[2])/float(line[1]))
        
x5=[]
y5=[]
with open("pagefaultdata_FIFOwithSecondChance.txt",'r') as f:
    Lines = f.readlines()
    for line in Lines:
        line = line.split();
        print(line)
        x5.append(int(line[0]))
        y5.append(float(line[2])/float(line[1]))
        
        
x6=[]
y6=[]
with open("pagefaultdata_NRU.txt",'r') as f:
    Lines = f.readlines()
    for line in Lines:
        line = line.split();
        print(line)
        x6.append(int(line[0]))
        y6.append(float(line[2])/float(line[1]))
        
        
x7=[]
y7=[]
with open("pagefaultdata_lru.txt",'r') as f:
    Lines = f.readlines()
    for line in Lines:
        line = line.split();
        print(line)
        x7.append(int(line[0]))
        y7.append(float(line[2])/float(line[1]))
        
x8=[]
y8=[]
with open("pagefaultdata_optimal.txt",'r') as f:
    Lines = f.readlines()
    for line in Lines:
        line = line.split();
        print(line)
        x8.append(int(line[0]))
        y8.append(float(line[2])/float(line[1]))

x9=[]
y9=[]
with open("pagefaultdata_random.txt",'r') as f:
    Lines = f.readlines()
    for line in Lines:
        line = line.split();
        print(line)
        x9.append(int(line[0]))
        y9.append(float(line[2])/float(line[1]))
        
x10=[]
y10=[]
with open("pagefaultdata_fifo.txt",'r') as f:
    Lines = f.readlines()
    for line in Lines:
        line = line.split();
        print(line)
        x10.append(int(line[0]))
        y10.append(float(line[2])/float(line[1]))

x11=[]
y11=[]
with open("pagefaultdata_nfu.txt",'r') as f:
    Lines = f.readlines()
    for line in Lines:
        line = line.split();
        print(line)
        x11.append(int(line[0]))
        y11.append(float(line[2])/float(line[1]))





  
# Initialise the subplot function using number of rows and columns

figure, axis = plt.subplots(3, 4)
plt.suptitle("Frames Vs PageFault Ratio")
# WsClock
axis[0, 0].plot(x1, y1)
axis[0, 0].set_title("Wsclock")
  
# Working Set
axis[0, 1].plot(x2, y2)
axis[0, 1].set_title("Working Set")

# aging
axis[0, 2].plot(x3, y3)
axis[0, 2].set_title("Aging")

# nfu
axis[0, 3].plot(x11, y11)
axis[0, 3].set_title("NFU")

# clock
axis[1, 0].plot(x4, y4)
axis[1, 0].set_title("Clock")

# FIFOsecond chance
axis[1, 1].plot(x5, y5)
axis[1, 1].set_title("FIFO Second Chance")


# NRU
axis[1, 2].plot(x6, y6)
axis[1, 2].set_title("NRU")

# lru
axis[1, 3].plot(x7, y7)
axis[1, 3].set_title("LRU")

# optimal
axis[2, 0].plot(x8, y8)
axis[2, 0].set_title("Optimal")

# Random
axis[2, 1].plot(x9, y9)
axis[2, 1].set_title("Random")

# fifo
axis[2, 2].plot(x10, y10)
axis[2, 2].set_title("FIFO")




figure.tight_layout()

figure.delaxes(axis[2,3])
# Combine all the operations and display
plt.show()
