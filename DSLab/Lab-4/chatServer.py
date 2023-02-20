import socket

s= socket.socket(socket.AF_INET, socket.SOCK_STREAM)

host= socket.gethostname()
port= 12345

s.bind((host, port))

s.listen(5)

con, addr= s.accept()
print("Recieved Connection from", addr[0], '(',addr[1],')')

s_name= con.recv(1024)
s_name= s_name.decode()
print(s_name, "has connected to the chat room \n ENTER [e] to exit chat room\n")
name= input('Enter your name :')
con.send(name.encode())

while True:
    message = input(str("Me : "))
    if(message=='e'):
        message= "Left chat room!"
        con.send(message.encode())
        print("\n")
        break
    con.send(message.encode())
    message= con.recv(1024)
    message= message.decode()
    print(s_name," : ", message)