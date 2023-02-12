import numpy as np



# Write a program to find the factors of a given number (get input from user) using for loop.
# num = int(input('Enter a number : '))
# print("Your number : ",num)

# print("The factors of the ", num,"are :")

# for i in range(1, num+1):
#     if num%i==0 :
#         print(i)





# Find the sum of columns and rows using axis.
# b= np.arange(12).reshape(3,4)
# print(b)
# print("Column sum: ", b.sum(axis=0)) #sum of each column
# print("Row sum: ", b.sum(axis=1)) #sum of each row


# Operations on Arrays (use numpy wherever required):
# a) Create array from list with type float

# mylist =[1,2,3,4,5]
# a = np.array(mylist, float)
# print(a)


# b) Create array from tuple
# myTuple =(1,2,3,4,5)
# a= np.array(myTuple)
# print(a)

# c) Creating a 3X4 array with all zeros
# a = np.zeros((3,4))
# print(a)


# d) Create a sequence of integers from 0 to 20 with steps of 5
# a = np.arange(0,20, 5)
# print(a)

# e) Reshape 3X4 array to 2X2X3 array
# a= np.arange(12).reshape(3,4)
# print(a)
# print(a.reshape(2,2,3))


# Write a program to transpose a given matrix
# b= np.arange(12).reshape(3,4)
# print(b)
# print(b.T)





# Write a program to add two matrices.
# a= np.arange(12).reshape(3,4)
# b= np.arange(12).reshape(3,4)

# print(a)
# print(b)
# c= a+b
# print(c)




# Write a program to find element wise product between two matrices
# a = np.array([1,2,3])
# print(a)

# b= np.array([4,5,6])
# print(b)

# for i in a:
#     for j in b:
#         print(i*j)





# f) Find maximum and minimum element of array, Row wise max and min, column wise max and min and sum of elements. (Use functions max(), min(), sum())

# a= np.arange(12).reshape(4,3)
# print(a)

# #sum of all elements
# sum=0

# for i in a:
#     for j in i:
#         sum= sum +j

# print("The sum of all  elements is :", sum)

# print("Max element in the array :",a.max())
# print("Min element in the array :",a.min())

# print("Row wise max and min respectively:")
# print(a.max(axis=1))
# print(a.min(axis=1))

# print("Column wise max and min respectively:")
# print(a.max(axis=0))
# print(a.min(axis=0))