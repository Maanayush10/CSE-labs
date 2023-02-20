import socket

s= socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

udp_host= socket.gethostname()
udp_port = 12345

while True:
    mssg =input('Enter a message :')

    print("UDP Target host :", udp_host)
    print("UDP Target port :", udp_port)

    s.sendto(mssg.encode(), (udp_host, udp_port))