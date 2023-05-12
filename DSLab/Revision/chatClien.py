import socket

s=socket.socket(socket.AF_INET, socket.SOCK_STREAM)
host= socket.gethostname()
port= 12345

s.connect((host, port))
name= input('Enter your name : ')
name= name.encode()
s.send(name)

while True:
    data= s.recv(1024)
    if not data:
        break
    data= data.decode()
    print('Server : ', data)
    text = input("You : ")
    text= text.encode()
    s.send(text)
s.close()