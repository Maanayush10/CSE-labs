#simple tcp connection
import socket
host= socket.gethostname()
port= 12345

s= socket.socket(socket.AF_INET, socket.SOCK_STREAM)

s.bind((host, port))
s.listen(5)

conn, addr=s.accept()
print('Welcome to server!')
print('Server waiting for connections')
print('Got a connection from ,', addr[0], ',', addr[1])
while True:
    data= conn.recv(1024)
    if not data:
        break
    print('The data received from client is : ', data.decode())
conn.close()
s.close()