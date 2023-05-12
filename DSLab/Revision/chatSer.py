import socket
s= socket.socket(socket.AF_INET, socket.SOCK_STREAM)
host= socket.gethostname()
port= 12345
s.bind((host, port))
s.listen(5)
conn, addr= s.accept()
name= conn.recv(1024)
name= name.decode()
print(name, " entered the chat!\n")
while True:
    msg=input("You : ")
    msg= msg.encode()
    conn.send(msg)
    text= conn.recv(1024)
    text= text.decode()
    print(name," : ",text)
conn.close()
s.close()
