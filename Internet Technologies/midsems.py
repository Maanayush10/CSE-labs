file= open('sample2.txt', 'r')
a= file.read()
print(a)
x= a.split()
print(x)
a =float(x[8])
b=float(x[17])
print('Average :', (a+b/2))