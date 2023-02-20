import socket
import sys

try:
    s= socket.socket(socket.AF_INET, socket.SOCK_STREAM)
except socket.err as err:
    print("Socket creation failed with error :",err)
    sys.exit()


print("Socket created successfuly")

target_host = input('Enter the name of the target host :')
target_port = input('Enter the target port :')

try :
    s.connect((target_host, int(target_port)))
except socket.error as err:
    print("Failed to connect to ", target_host," with port ", target_port)
    print("Error : ", err)
    sys.exit()


print("Connected successfully to ", target_host," with port ", target_port)