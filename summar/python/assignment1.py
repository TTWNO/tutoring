import os
import re
import socket
import pwd
import grp

#try to open a file in write mode
try:
    output_file = open('temp.txt', 'w')
#print error and exits
except:
    print("Error opening file")
    exit(1)

#get machine name
output_file.write(socket.gethostname() + "\n")

#get cpu information
#the information we want from /proc/cpuinfo
specList = ["processor", "vendor_id", "model", "model name", "cache size"]
#try to open a file in read mode
try:
    file = open("/proc/cpuinfo", "r")
    #prints the errors and exits
except:
    print("Error opening /proc/cpuinfo")
    exit(1)
#makes a list of lines from /proc/cpuinfo
lines = file.readlines()

# spec is one of the spec list items
for spec in specList:
#loops through every line in the /proc/cpuinfo
    for line in lines:
#searching the line to see if it matcches the spec list item
        if re.search(spec, line):
            output_file.write(line + "\n") 
            break                   #break loop after finding pattern


'''
Section for user information 
'''
#trying to get all the users
try:
    allUsers = pwd.getpwall()
#prints the error and exits
except:
    print("Error loading users.")
    exit(1)
#looping through all the users
for user in allUsers:
    #the group id of the current user
    gid = pwd.getpwnam(user.pw_name).pw_gid
    #turns the group id into a name
    userGroupName = grp.getgrgid(gid).gr_name
    # this is the equivalent to the line below
    '''
    allUserGroups = []
    for gp in grp.getgrall():
        if user in gp.gr_mem:
            allUserGroups.append(gp.gr_name)
    '''
    #this this code goes through every group on the system
    # if the current user is a memebr of the given group add to the list 
    allUserGroups = [gp.gr_name for gp in grp.getgrall() if user.pw_name in gp.gr_mem]
    #adds the users core group
    allUserGroups.append(userGroupName)
    #printingthe username with no new line
    output_file.write(user.pw_name + ": ")
    #joining all groups with a comma
    output_file.write(",".join(allUserGroups) + "\n")
#closing the output file
output_file.close()
#append to file by double arrows >>
#os.system is used to execute a command line program
#adding system services to now closed output file
os.system("systemctl list-units --type service >> temp.txt")

# rename file
os.system("mv temp.txt output.txt")