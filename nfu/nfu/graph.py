import matplotlib.pyplot as plt

x=[]
y=[]
with open("nfu_output.txt",'r') as f:
    Lines = f.readlines()
    for line in Lines:
        line = line.split();
        print(line)
        x.append(int(line[0]))
        y.append(float(line[1]))

print(x)
print(y)

 
# plotting the points
plt.plot(x, y)
 
# naming the x axis
plt.xlabel('No. Of Frames')
# naming the y axis
plt.ylabel('Page Fault Rate')
 
# giving a title to my graph
plt.title('NFU page Replacement')
 
# function to show the plot
plt.show()