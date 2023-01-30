# all the exercises of lab-1 are here.

# *****************************************************
# q1 finding the area of the triangle
# length = int(input("Enter length : "))
# breadth = int(input("Enter breadth : "))
# area= length*breadth
# print('Area of the rectangle is : ',area);


# *****************************************************
# q2 swapping 2 variables
# var =100;
# var2 =200;
# print("Both variables before swapping : ")
# print('var :',var," var2 :", var2)
# print("After swap :");
# temp= var;
# var=var2;
# var2=temp;
# print('var :',var," var2 :", var2)


# *****************************************************
# q3 check whether a number is even or odd
# var1 = int(input("Enter a number : "))
# if(var1%2 ==0) :

# 	print("The given number is even.");

# else:

# 	print("The given number is odd.");


# *****************************************************
# q4 check largest
# var1 = int(input("Enter number1 : "))
# var2 = int(input("Enter number2 : "))
# var3 = int(input("Enter number3 : "))
# if(var1> var2 and var1>var3) :

# 	print(var1," is the largest.");

# elif(var2> var1 and var2>var3):

# 	print(var2," is the largest.");
# else :
# 	print(var3," is the largest.");


# *****************************************************
# q5 list functions and operations in hello.py


# *****************************************************
#  q6 printing half of the values of a tuple in one line and half in other line

# mytuple =(1,3,5,7,9,2,4,6,8,10);
# tuple1 = mytuple[0:5]
# tuple2 = mytuple[5:10]
# print(mytuple)
# print(tuple1)
# print(tuple2)


# *****************************************************
#  q7 printing even values in one tuple, odd in another

# mytuple =(1,2,3,4,5,6,7,8,9,10);
# tuple1 =tuple()
# tuple2 =tuple()
# j=0
# k=0
# for i in range(len(mytuple)):
# 	if(mytuple[i]%2==0):
# 		tuple1[j]= mytuple[i]
# 		j=j+1
# 	else :
# 		tuple2[k]= mytuple[i]
# 		k=k+1

# print(mytuple)
# print(tuple1)
# print(tuple2)


# *****************************************************
#  q8 printing negative values from one tuple into a list

# mytuple = (-1, 2, 3, -4, 5, 6, 7, 8, 9, -10)

# mylist = list()
# i=0
# for i in range(len(mytuple)):
#     if(mytuple[i] < 0) :
#         mylist.append(mytuple[i])


# print(mylist)


# *****************************************************
#  q9 printing negative values from one tuple into a list

# mytuple = (-1, 2, 3, -4, 5, 6, 7, 8, 9, -10)
# print(mytuple)
# countPos=0
# countNeg =0
# mylist = list()
# i=0
# for i in range(len(mytuple)):
#     if(mytuple[i] < 0) :
#        countNeg = countNeg+1
#     else:
#         countPos= countPos+1

# print("Number of Negative numbers : ", countNeg)
# print("Number of Postive Numbers : ", countPos)


# *****************************************************
#  q10 remove all elements from the list
# mylist =[1,2,3,4,5]
# print("List before removing : ", mylist)
# mylist.clear()
# print("List after removing : ", mylist)
