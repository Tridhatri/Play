# Decorators are feature in python to extend the behaviour of functions, methods, classes without altering their actual code
# function decoratos
# They are the most common type and are used to wrap functions to add behaviour before or after their execution

def simple_decorator(func) :
    def wrapper():
        print("Before func execution")
        result = func()
        print("After func execution")
        return result 
    return wrapper 

#def simple_decorator2(func) :
    #print("Before func execution")
    #result = func()
    #print("After func execution")
    #return result 


@simple_decorator
def func():
    print("inside the function")


#@simple_decorator2
#def func2():
    #print("inside the function")
    #return None


#
#func()
#func()
#func2()

# Method decorators are specifically designed for methods within a class.
#def method_decorator(func):
   #def wrapper(self, *args, **kwargs):
       #print("Before method execution")
       #result = func(self, *args, **kwargs)
       #print("After method execution")
       #return result
   #return wrapper
#
#class MyClass:
   #@method_decorator
   #def say_hello(self):
       #print("Hello from MyClass!")
#obj = MyClass()
#obj.say_hello()



# Property method in python to work with instance attributes.

#class GFG:
    #def __init__(self, value):
        #self._value = value
#
    #def getter(self):
        #print("Getting value")
        #return self._value
#
    #def setter(self, value):
        #print("Setting value to " + value)
        #self._value = value
#
    #def deleter(self):
        #print("Deleting value")
        #del self._value
#
    #jar = property(getter, setter, deleter)
#
## Usage
#x = GFG("Happy Coding!")
#print(x.jar)
#
#x.jar = "Hey Coder!"
#del x.jar
#
#y = GFG("Happy play")
#print(y.jar)
#
#y.jar = "Hey Play!"
#print(x.jar)


# Property decorator to do the same thing but with decorator syntax

'''

class Man:
     def __init__(self, name):
         self._name = name if name else ''

     # Notice how all the property methods have the same names, based on the getter variable name
     # @property is used as the defualt getter
     @property
     def name(self):
         return self._name
     @name.setter
     def name(self, val):
         self._name = val
     @name.deleter
     def name(self):
         del self._name


p = Man(None)
print(p.name)
p.name = "Tridhatri"
print(p.name)
del p.name


'''

# Class decorators

'''
def class_decorator(cls):
   cls.class_name = cls.__name__
   return cls

@class_decorator
class Person:
   pass


print(Person.class_name)
'''


