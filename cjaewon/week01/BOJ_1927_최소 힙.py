"""
https://en.wikipedia.org/wiki/Heap_(data_structure)
https://en.wikipedia.org/wiki/Binary_heap
(최대) 힙, 이진힙 자료 : https://raw.githubusercontent.com/justiceHui/SSU-SCCC-Study/master/2023-summer-basic/slide/11-2-binary-heap.pdf
"""

import sys

n = int(input())
minheap = [0]

for i in range(n):
  x = int(sys.stdin.readline())

  if x == 0:
    if len(minheap) == 1:
      print(0)
    else:
      print(minheap[1])
      
      minheap[1] = minheap[len(minheap) - 1]
      minheap.pop()

      pos = 1

      while True:
        if pos * 2 > len(minheap) - 1: # 자식이 없는 경우
          break
        elif pos * 2 <= len(minheap) - 1 < pos * 2 + 1: # 자식이 하나 있는 경우
          if minheap[pos * 2] < minheap[pos]:
            minheap[pos * 2], minheap[pos] = minheap[pos], minheap[pos * 2]
          break # 완전 이진 트리이기 때문에 어차피 자식이 없으므로 종료
        else: # 자식이 두 개 있는 경우
          if minheap[pos] > min(minheap[pos * 2], minheap[pos * 2 + 1]): # 자식 모두 보다 큰 경우
            idx = min((minheap[pos * 2], pos * 2), (minheap[pos * 2 + 1], pos * 2 + 1), key=lambda n: n[0])[1]
            minheap[idx], minheap[pos] = minheap[pos], minheap[idx]
            pos = idx
          elif minheap[pos] > minheap[pos * 2]: # 자식 하나보다 큰 경우
            minheap[pos], minheap[pos * 2] = minheap[pos * 2], minheap[pos]
            pos = pos * 2
          elif minheap[pos] > minheap[pos * 2 + 1]: # 자식 하나보다 큰 경우
            minheap[pos], minheap[pos * 2 + 1] = minheap[pos * 2 + 1], minheap[pos]
            pos = pos * 2 + 1
          else: # 자식보다 작거나 같은 경우
            break
  else:
    minheap.append(x)

    pos = len(minheap) - 1

    while pos // 2 > 0:
      if minheap[pos // 2] > minheap[pos]:
        minheap[pos // 2], minheap[pos] = minheap[pos], minheap[pos // 2]
        pos = pos // 2
      else:
        break    

