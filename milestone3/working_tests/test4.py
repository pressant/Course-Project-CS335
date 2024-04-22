def add(a:int, b:int)->None:
    c:int = 0
    i:int = 0
    c = b + a
    for i in range(a):
      c = c + b
    print(c)


def main():
    x:int = 5
    z:int = 6
    add(x,z)
    