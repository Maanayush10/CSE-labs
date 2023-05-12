import socket

s= socket.socket(socket.AF_INET, socket.SOCK_STREAM)
host= socket.gethostname()
port= 12345
s.connect((host, port))
while True:
    msg= s.recv(1024)
    print(msg.decode())
    data=input('Enter string to be sent:')
    data= data.encode()
    s.send(data)
    serverDat= s.recv(1024)
    print('Data from the server is : ', serverDat.decode())