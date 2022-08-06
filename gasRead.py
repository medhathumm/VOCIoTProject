import serial
import time

ser = serial.Serial('/dev/cu.usbmodem144401',115200) # This is mac port for windows it will be like COM1
time.sleep(2);

for i in range(50):

    line = ser.readline()  # read a byte
    if line:
        string = line.decode()
        print(string)
        string = line.decode()

ser.close() # close the connection
