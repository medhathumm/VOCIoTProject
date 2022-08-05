"""
This example below reads data from a sensor till five values and then it writes into a text file. Please pay attention to the range and how to deal with the last element
"""
import serial
import time
import matplotlib.pyplot as plt
import sys

ser = serial.Serial('COM4',115200) # This is mac port for windows it will be like COM1
data ={}
time =[60,120,180,240,300,360,420,480,540,600];
count=1 
for t in time:
   data[t] = 0.0
while count <=30:
    line = ser.readline()  # read a byte
    string = line.decode()
    #print(string)
    if 'BME' not in string: 
        #print(len(string),string,string[0],string[1])
        string_list = string.split()
        #print(string_list)
        #print(string_list[1])
        index = ( count -1 ) % 10
        #print(index, time[index])
        farTemp = ((float(string_list[1]) * 9) / 5) + 32
        data[time[index]] += float(farTemp)
        print(data) #personal preference so that I can see the data loading
        count +=1
        
ser.close() # close the connection
"""
with open(sys.argv[1]+".txt", "w") as  output:
  for i in range(0,len(data)):
    if i != len(data)-1:
      output.write(str(data[i]))
      output.write(",")
      print("writing record", i, data[i])
    else:
      output.write(str(data[4]))
output.close()
"""
for k,v in data.items():
   data[k] = v/3 # Since count is 30, I'm dividing by 3
interval = list(data.keys())[0]

x_data = {}
for k, v in data.items():
    x_data[k - interval/2] = v

time = list(x_data.keys())
values = list(x_data.values()) # count is 30 so I am dividing by 3

fig = plt.figure(figsize=(10, 7))

plt.bar(time, values, color='olive', width=interval)
plt.xlim(xmin=0, xmax=list(data.keys())[-1])

plt.xlabel("Time (ms)")
plt.ylabel("Temp Value (F)")
plt.title("Temperature Reading")
plt.show()

