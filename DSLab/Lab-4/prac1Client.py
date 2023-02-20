import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# we can also use 127.0.0.1 as that is the server's address
host = socket.gethostname()
port = 12345

s.connect((host, port))
s.sendall(b"Hello, message from the client")

data = s.recv(1024)
print("Recieved connection.")
print("Data recieved is :", data.decode())
