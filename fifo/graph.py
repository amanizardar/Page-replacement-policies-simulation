import matplotlib.pyplot as plt

x=[]
y=[]
with open("fifo_output.txt",'r') as f:
    Lines = f.readlines()
    for line in Lines:
        line = line.split();
        print(line)
        x.append(int(line[0]))
        y.append(float(line[1]))

print(x)
print(y)

 
# # x axis values
# x = [1,2,3]
# # corresponding y axis values
# y = [2,4,1]
 
# plotting the points
plt.plot(x, y)
 
# naming the x axis
plt.xlabel('No. Of Frames')
# naming the y axis
plt.ylabel('Page Fault Rate')
 
# giving a title to my graph
plt.title('FIFO page Replacement')
 
# function to show the plot
plt.show()