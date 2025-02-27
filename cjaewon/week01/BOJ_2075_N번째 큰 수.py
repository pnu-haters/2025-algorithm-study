import sys
import heapq

"""
첫 번째 시도 : 1500 ^ 2이기 때문에 이중 for문 상관없이 1초안에 실행될 것이라 생각하고 max heap에 모두 대입 -> 메모리 초과 실패 (python3 int형은 28byte -> 대략 60mb)
두 번째 시도(해결) : 모든 요소를 순회하면서 minheap에 비교해보고 더 크면 대입하는 방식으로 n으로 고정하여 해결
 - (n으로 고정하는 이유는 더 이상 필요하지 않기 때문)
 - (또한 table로 저장해두면 안되고 inpyt 받는 즉시 해결해야함)
"""


n = int(input())
minheap = []

for i in range(n):
  for val in list(map(int, sys.stdin.readline().rstrip().split())):
    if len(minheap) == n:
      if minheap[0] < val:
        heapq.heappop(minheap)
        heapq.heappush(minheap, val)
    else:
      heapq.heappush(minheap, val)


print(minheap[0])



  
