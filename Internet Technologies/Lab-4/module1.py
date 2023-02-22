#Write a Python class to implement pow(x, n)
class Power:
    def __init__(self, num, pow):
        self.num= num
        self.pow= pow
    def power(self):
        return self.num ** self.pow

a = int(input('Enter the Number'))
b = int(input('Enter the exponent'))

ex =Power(a,b)
 
#pow.num= a;
#pow.pow =b;

print(ex.power())
