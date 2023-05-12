import socket

s=socket.socket(socket.AF_INET, socket.SOCK_STREAM)

host= socket.gethostname()
port= 12346

s.bind((host, port))
s.listen(5)
conn, addr=s.accept()
while True:
    msg="Welcome to the server!"
    msg= msg.encode()
    conn.send(msg)
    data= conn.recv(1024)
    if not data:
        break
    data = data.decode()
    print('Data received from client is: ', data)

conn.close()
s.close()
