import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

host = socket.gethostname()
port = 12345

s.bind((host, port))
s.listen()
conn, addr = s.accept()

with conn:
    print("Connected by :", addr)
    while True:
        data = conn.recv(1024)
        if (data):
            print("Data from client : ", data.decode())
            data = input('Enter a message to be sent to client : ')

            if not data:
                break
            # sending message as bytes to client
            conn.sendall(bytearray(data, 'utf-8'))

conn.close()
