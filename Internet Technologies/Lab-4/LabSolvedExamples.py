#class Person:
#   "This is a Person class"
#    age=10

#    def greet(self):
#        print("Hello this is Ayushman")
        


#harry= Person()
#print(Person)
#print(Person.age)
#print(Person.greet)
#print(harry.greet())



class Human:
    species  = "Homo-sapiens"
    def __init__(self, name):
        self.name = name
        self.age = 0
    def say(self, msg):
        print("{name} : {message}".format(name= self.name, message =msg))

    def sing(self):
        return "yo..yo...microphone check...one two...one two.."

    @classmethod
    def get_species(cls):
        return cls.species
    @staticmethod
    def grunt():
        return "*grunt*"
    @property
    def age(self):
        return self._age
    @age.setter
    def age(self, age):
        self._age=age

    @age.deleter
    def age(self):
        del self._age

if __name__=='__main__':
    i= Human(name= "Ian")
    i.say("hi")
    j= Human("Joel")
    j.say("hello")

    i.say(i.get_species())
    j.say(j.get_species())

    print(Human.grunt())

    print(i.grunt())

    i.age= 42
    i.say(i.age)
    j.say(j.age)

    del i.age