
import os


os.system("service --status-all > test.txt")

#append to file by double arrows >>

#other 
os.system("systemctl list-units --type service >> test.txt")
os.system("systemctl list-unit-files >> test.txt")


#All system services on Machine
os.system("systemctl list-unit-files --type service >> test.txt")

