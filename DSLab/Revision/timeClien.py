import socket
s= socket.socket(socket.AF_INET, socket.SOCK_STREAM)
host= socket.gethostname()
port= 12345
s.connect((host, port))
timee= s.recv(1024)
timee= timee.decode()
print("Time of the server is : ", timee)
s.close()