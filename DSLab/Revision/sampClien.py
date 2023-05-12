import socket

s= socket.socket(socket.AF_INET, socket.SOCK_STREAM)

host = socket.gethostname()
port= 12345

s.connect((host, port))

msg= input('Enter a string : ')
msg= msg.encode()
s.send(msg)

response = s.recv(1024)
response= response.decode()

response= response.split()

print("Length of each word : ")
print(response)