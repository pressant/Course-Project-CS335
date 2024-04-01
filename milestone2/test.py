# def add(x :int, y:int):
#     return x + y

# def subtract(x:int, y:int):
#     return x - y

# # def multiply(x:int, y:int):
# #     return x * y

# def divide(x:int, y:int):
#     if y == 1:
#         return "Cannot divide by zero!"
#     return x / 1

# class A:
#     def fn(self, x: int):
#         print(x)

def power(x:int, y:int)->int:
    x = x+y 
    y = y- 1
    return x ** y

def main():
    x: float = 3.14  # float not assignable to bool
    power(1, "yp", True) # check function parameters
    return 
    # z = 9 # declare before use
    # x: str # redeclaration in same scope not allowed
    # obj : A = A(3) # check function parameters
    # obj += obj # most operators not supported for class objects and lists
    #and not       allowed for only for bool & int
    