import socket

s= socket.socket(socket.AF_INET, socket.SOCK_STREAM)

host= socket.gethostname()
port= 12345

try:
    s.connect((host, port))
except socket.error as e:
    print(str(e))

while True:
    welcomMsg=s.recv(1024)
    print(welcomMsg.decode())
    myMsg= input('Enter something to send : ')
    s.send(myMsg.encode())