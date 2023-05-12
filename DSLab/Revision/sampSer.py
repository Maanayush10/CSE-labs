import socket

s= socket.socket(socket.AF_INET, socket.SOCK_STREAM)

host= socket.gethostname()
port= 12345

s.bind((host, port))

s.listen(5)
conn, addr= s.accept()

data= conn.recv(1024)
data= data.decode()
data= data.split()
lenOfEachWord=' '
print(data)
for i in range(len(data)):
    lenOfEachWord+= " "+str(len(data[i]))
lenOfEachWord= lenOfEachWord.encode()
conn.send(lenOfEachWord)
conn.close()
s.close()