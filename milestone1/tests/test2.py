# Custom Test Case
class Point:
    def __init__(self, x: int, y: int):
        self.x: int = x
        self.y: int = y

    def move(self, dx: int, dy: int) -> None:
        self.x += dx
        self.y += dy

    def distance_from_origin(self) -> float:
        return (self.x ** 2 + self.y ** 2) ** 0.5

class Rectangle:
    def __init__(self, width: float, height: float):
        self.width: float = width
        self.height: float = height
        self.corner: Point = Point(0, 0)

    def area(self) -> float:
        return self.width * self.height

    def perimeter(self) -> float:
        return 2 * (self.width + self.height)

    def move_to(self, x: int, y: int) -> None:
        self.corner.move(x - self.corner.x, y - self.corner.y)

def main():
    rect: Rectangle = Rectangle(5.0, 10.0)
    print("Initial Area:", rect.area())
    print("Initial Perimeter:", rect.perimeter())

    rect.move_to(2, 3)
    print("After Moving: Area:", rect.area())
    print("After Moving: Perimeter:", rect.perimeter())

    print("Distance from Origin:", rect.corner.distance_from_origin())

if __name__ == "__main__":
    main()
