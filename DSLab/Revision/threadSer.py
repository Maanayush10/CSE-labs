import socket
from _thread import *

s= socket.socket(socket.AF_INET, socket.SOCK_STREAM)
host= socket.gethostname()
port = 12345
threadCount=0
try:
    s.bind((host, port))
except socket.error as e:
    print(str(e))
s.listen(5)
print("Waiting for connections")

def threaded_client(connection):
    connection.send(str.encode('Welcome to server'))
    while True:
        data=connection.recv(1024)
        if not data:
            break
        print('Received form client ', str(threadCount), ' : ', data.decode())
        msg= input('Server says : ')
        connection.send(msg.encode())
    connection.close()


while True:
    client, addr= s.accept()
    print('Connected to :', addr[0],', ', addr[1])
    start_new_thread(threaded_client, (client,))
    threadCount+=1
    print('Thread number : ', threadCount)