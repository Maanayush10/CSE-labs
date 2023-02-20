import socket
import sys

try:
    s= socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    print("Socket successfully created.")
except socket.err as err:
    print("Socket creation failed with error :", err)
    sys.exit()

port =80

try:
    host_ip= socket.gethostbyname('www.google.com')
except socket.gaierror:
    print("Couldnot resolve host! Error")
    sys.exit()

s.connect((host_ip, port))
print("Socket has sucessfully connected to google")

# ip = socket.gethostbyname('www.google.com')
# print(ip)
