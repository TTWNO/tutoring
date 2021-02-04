import os
import re
import socket


#get machine name
print(socket.gethostname())


#get cpu information

specList = ["processor", "vendor_id", "model", "model name", "cache size"]

file = open("/proc/cpuinfo", "r")
lines = file.readlines()

for spec in specList:               
    for line in lines:
        if re.search(spec, line):
            print(line)
            break                   #break loop after finding pattern
