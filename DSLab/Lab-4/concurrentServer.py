import socket
import os
# import _thread
from _thread import *

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
host = '127.0.0.1'
port = 12345

ThreadCount = 0
try:
    s.bind((host, port))
except socket.error as e:
    print(e)

print('Waitiing for a Connection..')
s.listen(5)


def threaded_client(connection):
    connection.send(str.encode('Welcome to the Server'))


    while True:
        data = connection.recv(2048)
        print('Received from client :' + str(ThreadCount) + data.decode())
        Inputs = input('Server Says: ')
        if not data:
            break
        connection.sendall(Inputs.encode())
    connection.close()

while True:
    Client, address = s.accept()
    print('Connected to: ' + address[0] + ':' + str(address[1]))
    start_new_thread(threaded_client, (Client, ))
    ThreadCount += 1
    print('Thread Number: ' + str(ThreadCount))
s.close()
