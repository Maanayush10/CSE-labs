import socket

s= socket.socket(socket.AF_INET, socket.SOCK_STREAM)
host= socket.gethostname()
port= 12345

s.bind((host, port))
s.listen(5)

conn, addr=s.accept()
while True:
    msg="\nWelcome to the server!"
    msg= msg.encode()
    conn.send(msg)
    data= conn.recv(1024)
    data= data.decode()
    print('Client : ',data)
    data = data.encode()
    conn.send(data)
