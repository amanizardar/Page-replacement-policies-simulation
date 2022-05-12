##### ReadMe of Project Titled "PAGE REPLACEMENT POLICIES SIMULATION"
&nbsp;
###### Note: Temporary files will be created during the Execution of the program and they will be Deleted Automatically.
&nbsp;
# Dependencies and Requirements:
- C++ for Compiling and running various Page Replacement algo
- Python 3 for Plotting Graphs
- Matplotlib Library 
```sh
        python -m pip install -U matplotlib
```
- Gui Widget Toolkit
```sh
        pip install pyqt5
```
- Bash Shell To run Run.sh Script

## Input Format
Input will be in Multiple Lines
Each test case will be in a Single Line
First integar of each line will be No. Of the Frames a Process has, Followed by page stream, Followed By a coma and Dirty Page Information bits.
All the values in a line are space seprated.

    Example Testcase 1 :
    2 1 1 2 4 5 7 5 1 2 3 4 , 1 0 0 0 0 0 0 0 0 0 1

    Example Testcase 2 :
    3 2 1 2 1 2 5 1 4 2 5 , 0 0 0 0 1 1 1 0 0 1

    Example Testcase 3 :
    4 5 2 1 4 1 2 5 1 4 2 , 1 0 1 0 1 1 0 0 0 0


# How To Run
Just open a terminal and Execute
```sh
./run.sh
```
This bash script will compile all c++ files and Execute them.
Data of Each algo will be Stored in Pagefaultdata_<algoname>.txt files 
these Files will be opened by Python Program and it will Plot Total 22 Graphs.

There are 2 types of Graph:
- No. of Frames Vs Page Fault Ratio
- No. of Frames Vs No. Of Swaps

# Team Name : QuadSquad
## Team Members :
- Diksha Daryani(2021201045) 
- Aman Izardar(2021201028) 
- Annapoorani. A(2021201017)  
- Ayush Mittal(2021201030)
