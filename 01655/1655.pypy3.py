from sys import stdin
from sys import stdout
import heapq
class median_heap:
    def __init__(self):
        self.max_heap = []
        self.min_heap = []
    
    def insert(self, item):

        # len(max_heap) == len(min_heap) or len(max_heap) == len(min_heap)+1
        if len(self.max_heap) > len(self.min_heap):
            heapq.heappush(self.min_heap, item)
        else:
            #파이썬은 최소힙이 기본이므로 -1을 곱해서 넣음 
            heapq.heappush(self.max_heap, -item)
        
        #max_heap.top() > min_heap.top() 이면 swap 
        if len(self.min_heap) and -self.max_heap[0] > self.min_heap[0]:
            maxtop = heapq.heappop(self.max_heap)
            mintop = heapq.heappop(self.min_heap)

            heapq.heappush(self.max_heap, -mintop)
            heapq.heappush(self.min_heap, -maxtop)
    
    def top(self):
        return -self.max_heap[0]

N = int(stdin.readline())
heap = median_heap()

for _ in range(N):
    k = int(stdin.readline())
    heap.insert(k)
    stdout.write(str(heap.top())+"\n")