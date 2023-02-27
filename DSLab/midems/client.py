import socket

s= socket.socket(socket.AF_INET, socket.SOCK_STREAM)

host = '127.0.0.1'
port = 12350

conn=s.connect((host, port))
num = (input('Enter the number :'))
# num= num.encode()
s.send(num.encode('ascii'))

data= s.recv(1024)
data= data.decode()
print("Sum of all digits :", data)


