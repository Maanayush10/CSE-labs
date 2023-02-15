def binSearch(num, start, end, key):
    mid= (start+end)//2
    if(num[mid]==key):
        return mid
    elif(num[mid]<key):
        return binSearch(num, mid+1, end, key)
    elif(num[mid]>key):
        return binSearch(num, start, mid-1, key)
    return -1

num= [1,2,3,4,5,6,7,8,9,10]
print(num)
key= 4
print("key :", key)
index = binSearch(num, 0, len(num)-1, key)
print("The index returned is : ", index)