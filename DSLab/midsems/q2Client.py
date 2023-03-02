import socket

s= socket.socket()

host = socket.gethostname()
port= 12375

s.connect((host, port))

num= input('Enter a number to check:')
num=str(num)
s.send(num.encode('ascii'))

data= s.recv(1024)
print(data.decode())

