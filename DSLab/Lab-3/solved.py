# import numpy as np


# array creation
# A= np.array([2,5,10])
# print(A)
# print(A.dtype)


# creating a sequence of sequence will create 2D array

# A= np.array([(3,4,5) ,(12,6,1)])
# print(A)

# Z= np.zeros((2,4))
# print(Z)

# Y= np.ones((2,2))
# print(Y)


# To create a sequence of data
# S= np.arange(10,30,5)
# print(S)

# P= np.arange(0,2, 0.3)
# print(P)


# Instead of step-size we can specify total number of elements in the array using

# S1= np.linspace(0,2,9) #produce 9 numbers starting with 0 and ending with 2
# print(S1)


# usage of Random number functions
# import random
# print(random.choice([1,2,3,4,5]))
# print(random.choice("Python"))
# print(random.randrange(25,50))
# print(random.randrange(25,50 ,2))
# print(random.random())
# print(random.uniform(5,10))
# A=random.shuffle([1,2,3,4,5]) #idk why but gives me none
# print(A)
# print(random.seed(10)) #same problem of none here


# 2D array [Matrix]

# a= np.arange(15).reshape(3,5)
# print(a)
# print(a.shape)
# print(a.T)


# 3D array
# c = np.arange(24).reshape(2,3,4)
# print(c)
# print(c.shape)
# print(c[1,:,:])


# array operations
# a= np.array([20,30,40,50])
# b= np.arange(4)

# c= a-b

# print(a)
# print(b)
# print(c)
# print(b**2)
# print(10*np.sin(a))
# print(a<35)


# matrix operations

# A= np.array([[1,1],[0,1]])
# B= np.array([[2,0],[3,4]])
# print(A)
# print(B)
# print(A*B)
# print(A.dot(B))

# b= np.arange(12).reshape(3,4)
# print(b)
# print(b.sum(axis=0)) #sum of each row
# print(b.sum(axis=1)) #sum of each column


# indexing, slicing & iterating Array
# a= np.arange(10)**3
# print(a)
# print(a[2:5])
# print(a[0:6:2])

# b = np.array([[0, 1, 2, 3],
#               [10, 11, 12, 13],
#               [20, 21, 22, 23],
#               [30, 31, 32, 33],
#               [40, 41, 42, 43]])
# print(b)
# print(b[2,3])
# print(b[0:5,2]) #prints first 5 elements of 2 col
# print(b[-1,:]) #fetches last row
# print(b[:,-1]) #fetches last col


# for row in b:
#     print(row) #will print every row

# for element in b.flat:
#     print(element) #show all elements of 1D array


# changing the shape of the matrix
# print(b.ravel())
# B1= b.reshape(4,5)
# print(B1)


# stacking different arrays together
# A1 = np.array([(3,4,5),(12,6,1)])
# print(A1)
# A2 = np.array([(1,2,6),(-4,3,8)])
# print(A2)

# D1 =np.vstack((A1, A2))
# print(D1)

# D2= np.hstack((A1,A2))
# print(D2)


# stacking 1D array into 2D column
# a = np.array([4., 2.])
# b = np.array([3., 8.])
# print(np.column_stack((a, b)))  # returns 2D array

# print(np.hstack((a,b)))

# print(
#     np.hstack((a[:,newaxis], b[:,newaxis]))
# )#doesnot work




#indexing with array of indices
# a= np.arange(12)**2
# print(a)
# i=np.array([1,1,3,8,5])
# print(a[i])

# j= np.array([[3,4],[9,7]])
# print(a[j])



#usinf for loop (mapping by index)
#calculate the sum of all elements of a 2D Numpy Array(iterate over a range)
# a = np.array([(3,2,9), (1,6,7)])
# print(a)
# sum=0

# for row in a:
#     for col in row:
#         sum+=col

# print(sum)


# mapping by index
# summ=0
# for row in range(a.shape[0]):
#     for col in range(a.shape[1]):
#         summ+=a[row, col]

# print(summ)
