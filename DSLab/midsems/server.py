#TCP program to send Number to a server and server prints the sum of digits

import socket

s= socket.socket(socket.AF_INET, socket.SOCK_STREAM)

host = '127.0.0.1'
port = 12350

s.bind((host, port))
s.listen(5)
conn, addr= s.accept()

print("Recieved connection from :", addr[0], addr[1])

# while True:
print("Waiting for client...")
num= conn.recv(1024)
num= num.decode()
num= int(num)
sum=0
print("Number Recieved :", num)

while(num!=0):
    ones = num%10
    num= num//10
    sum= sum+ones



# sum= ones+tens+hundreds+th

print("Sum generated :", sum)
    # sum= sum.encode()
sum=str(sum)
conn.send(sum.encode('ascii'))

s.close()
