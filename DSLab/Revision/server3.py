import socket


def myfunc(num):
    sumOfDig=0
    while(num!=0):
        sumOfDig+= num%10
        num = num//10
    return sumOfDig

s= socket.socket(socket.AF_INET, socket.SOCK_STREAM)
host= socket.gethostname()
port= 12345

s.bind((host, port))

s.listen(5)

conn, addr=s.accept()
sumNum=[]
evenSum=0
oddSum=0
print('TCP SERVER has started and is ready to receive\n')
print('Received connection from: ', addr[0] ,',',addr[1])
myList=[]

data= conn.recv(1024)
data= data.decode()
data = data.split()

for i in range(len(data)):
    myList.append(myfunc(int(data[i])))

print("The sum of digits : ",myList)

for i in range(len(myList)):
    if(myList[i]%2==0):
        evenSum+=myList[i]
    else:
        oddSum+=myList[i] 

evenSum = str(evenSum)
oddSum= str(oddSum)

evenSum= evenSum + " "+oddSum
evenSum= evenSum.encode()
conn.send(evenSum)

# oddSum= oddSum.encode()
# conn.send(oddSum)
conn.close()
s.close()
