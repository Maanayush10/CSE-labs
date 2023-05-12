import socket
s= socket.socket(socket.AF_INET, socket.SOCK_STREAM)

host= socket.gethostname()
port= 12345

s.connect((host, port))

num= input("Enter your numbers with spaces between them : ")

data = num.encode()
s.send(data)
dataOne= s.recv(2048)
dataOne= dataOne.decode()
dataTwo= dataOne.split()
print("Even Sum : ", int(dataTwo[0]))
print("Odd sum : ", int(dataTwo[1]))