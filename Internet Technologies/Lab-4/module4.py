class Pair:
    def findPair(self, arr, target):
        myList =[]
        for i in range(0,(len(arr))):
            for j in range(i,(len(arr))):
                if (arr[i]+arr[j])==target:
                    myList.append([i,j])
        return myList
        

arr=[10, 20, 10, 40 , 50, 60, 70]
target= 50

newSol= Pair()

print(newSol.findPair(arr, target))