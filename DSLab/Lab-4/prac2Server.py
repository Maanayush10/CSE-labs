import socket
import time

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

#we use the below function to avoid the error 'OSError: [Errno 98] Address already in use'
# s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

host = socket.gethostname()
port = 12345

s.bind((host, port))
s.listen(5)

while True:
    clientSock, addr = s.accept()
    print("Got a connection from ", addr)
    currentTime = time.ctime(time.time())+"\r\n"
    clientSock.send(currentTime.encode('ascii'))
    clientSock.close()
