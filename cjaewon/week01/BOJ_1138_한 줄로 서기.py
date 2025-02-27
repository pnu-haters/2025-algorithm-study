"""
단순 구현
"""

import sys

n = int(input())

people = list(map(int, sys.stdin.readline().rstrip().split()))
result = [0 for i in range(n)]

for i, person in enumerate(people):
  # i + 1
  cnt = 0
  
  for j in range(len(result)):
    if cnt == person and result[j] == 0:
      result[j] = i + 1
      break
  
    if result[j] == 0:
      cnt += 1

print(" ".join(map(str, result)))