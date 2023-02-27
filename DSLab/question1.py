mylist1=[(3,3,3),(22,12,60),(12,18,21)]
mylist2=[]
for i in mylist1:
    sum=0
    for j in i:
       sum = sum+j
    mylist2.append(sum)

print(mylist2)