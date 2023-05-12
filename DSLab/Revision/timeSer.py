import socket
import time

host= socket.gethostname()
port= 12345

s= socket.socket(socket.AF_INET, socket.SOCK_STREAM)

s.bind((host, port))
s.listen(5)
while True:
    conn, addr=s.accept()
    print('Got a connection from : ', addr[0], ', ', addr[1])
    timee= time.ctime(time.time())
    timee= timee.encode()
    conn.send(timee)
    conn.close()
