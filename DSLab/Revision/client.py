import socket
s= socket.socket(socket.AF_INET, socket.SOCK_STREAM)
host= socket.gethostname()
port=12345
s.connect((host, port))

num= input('Enter a number to be sent:\t')
num =num.encode()
s.send(num)
