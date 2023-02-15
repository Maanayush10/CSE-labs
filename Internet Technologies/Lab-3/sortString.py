string = input("Enter a string  :")

words = [string.lower() for string in string.split()]

words.sort()

print("The sorted list of words are :")
for word in words:
    print(word)
