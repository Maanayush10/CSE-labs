import socket

s= socket.socket(socket.AF_INET, socket.SOCK_STREAM)

host= socket.gethostname()
port= 12346

s.connect((host, port))

while True:
    msg= s.recv(1024)
    print(msg.decode())
    if not msg:
        break
    data=input('Input a string: ')
    data = data.encode()
    s.send(data)
s.close()