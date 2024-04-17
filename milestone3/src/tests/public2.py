data: list[float] = [-2.3, 3.14, 0.9, 11.0, -9.1] 

min_value: float = 2.3

def compute_min() -> float:
  min_value: float = 0.0
  a: float = data[0]
  return a


def compute_avg(data : list[float]) -> float:
  avg_value: float = 0.0
  sum: float = 0.0
  i: int = 0
  for i in range(len(data)):
    sum += data[i]
  return sum / len(data)


def main():
  a: list[float] = [1.1,2.1]
  b: float = compute_avg(a) 
  print("Average value: ")


if __name__ == "__main__":
  main()
