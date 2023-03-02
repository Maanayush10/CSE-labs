import socket

s= socket.socket()

host = socket.gethostname()
port= 12375

s.bind((host,port))
s.listen(5)
conn,addr=s.accept()

print("Connected with : ", addr[0], addr[1])

data= conn.recv(1024)
sum=0
data= data.decode()
data = int(data)
x= data

print("The number recieved is ",x)

while(x!=0):
    num = x%10
    x=x//10
    num =num**3
    sum= sum+num

print("Value of sum:", sum)
if(sum == data):
    msg="The given number is Armstrong number"
    conn.send(msg.encode('ascii'))
else:
    msg="The number is not Armstrong number"
    conn.send(msg.encode('ascii'))