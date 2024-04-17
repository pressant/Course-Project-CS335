def add(x :int, y:int)->int:
    return x + y

def subtract(x:int, y:int)->int:
    return x - y

def multiply(x:int, y:int)->int:
    return x * y

def divide(x:int, y:int)->float:
    if y == 0:
        return 1.1
    return x / y

def power(x:int, y:int)->int:
    return x ** y

def main():
    # while True:
        # choice:int = int(input("Enter choice (1/2/3/4/5): "))
        # if choice in (1, 2, 3, 4, 5):
        #     break
        # else:
        #     print("Invalid choice! Please enter a number between 1 and 5.")
    num1:int
    num2:int
    choice:int 
    if choice == 1:
        print(num1, "+", num2, "=", add(num1, num2))
    else:
        print(num1, "-", num2, "=", subtract(num1, num2))

if __name__ == "__main__":
    main()
