data: list[float] = [-2.3, 3.14, 0.9, 11, -9.1] 

min_value: float = 2.3

def compute_min() -> float:
  min_value: float = 0
  a: float = data[0]
  return a


def compute_avg(data : list[float]) -> int:
  avg_value: float = 0
  sum: int = 0
  i: int = 0
  for i in range(len(data)):
    sum += data[i]
  return sum / len(data)


def main():
  a: list[int] = [1,2]
  b: int = compute_avg(a) 
  print("Average value: ")


if __name__ == "__main__":
  main()
