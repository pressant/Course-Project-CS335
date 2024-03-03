class MinHeap:
    def __init__(self):
        self.heap = []

    def parent(self, i):
        return (i - 1) // 2

    def left_child(self, i):
        return 2 * i + 1

    def right_child(self, i):
        return 2 * i + 2

    def insert(self, value):
        self.heap.append(value)
        self.heapify_up(len(self.heap) - 1)

    def heapify_up(self, i):
        while i > 0 and self.heap[self.parent(i)] > self.heap[i]:
            self.heap[self.parent(i)], self.heap[i] = self.heap[i], self.heap[self.parent(i)]
            i = self.parent(i)

    def heapify_down(self, i):
        smallest = i
        l = self.left_child(i)
        r = self.right_child(i)

        if l < len(self.heap) and self.heap[l] < self.heap[smallest]:
            smallest = l
        if r < len(self.heap) and self.heap[r] < self.heap[smallest]:
            smallest = r

        if smallest != i:
            self.heap[i], self.heap[smallest] = self.heap[smallest], self.heap[i]
            self.heapify_down(smallest)

    def extract_min(self):
        if len(self.heap) == 0:
            return None
        if len(self.heap) == 1:
            return self.heap.pop()

        min_val = self.heap[0]
        self.heap[0] = self.heap.pop()
        self.heapify_down(0)
        return min_val

    def get_min(self):
        return self.heap[0] if self.heap else None

    def heapify(self, arr):
        self.heap = arr[:]
        n = len(arr)
        for i in range(n // 2, -1, -1):
            self.heapify_down(i)

    def print_heap(self):
        print("MinHeap:", self.heap)


def main():
    heap = MinHeap()
    arr = [3, 2, 1, 7, 8, 4, 10, 16, 12]
    heap.heapify(arr)
    heap.print_heap()  # Output: MinHeap: [1, 2, 3, 7, 8, 4, 10, 16, 12]
    
    heap.insert(5)
    heap.print_heap()  # Output: MinHeap: [1, 2, 3, 5, 8, 4, 10, 16, 12, 7]
    
    min_val = heap.extract_min()
    print("Extracted min:", min_val)  # Output: Extracted min: 1
    heap.print_heap()  # Output: MinHeap: [2, 5, 3, 7, 8, 4, 10, 16, 12]

if __name__ == "__main__":
    main()

