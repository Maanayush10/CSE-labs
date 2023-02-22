#Write a Python class which has two methods get_String and print_String. get_String accept a string from the user and print_String print the string in upper case

class StringExample:
    def get_string(self):
        self.name = input('Enter a string :')
    def print_string(self):
        print("String is :", self.name.upper())


Ayush = StringExample()

Ayush.get_string()
Ayush.print_string()