mylist =[(1,2,3), (4,5,6),(7,8,9)]
evenList =[]
oddList = []

for i in mylist:
    for j in i:
        if(j%2==0):
            evenList.append(j)
        else:
            oddList.append(j)

print(mylist)
print(evenList)
print(oddList)