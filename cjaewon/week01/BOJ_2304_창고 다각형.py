"""
max 함수 남발 유의
"""

cad = [0 for i in range(1005)] # idx : 0 ~ 1000

for i in range(int(input())):
  l, h = map(int, input().split())
  cad[l] = h

area = 0
height = 0

for i in range(1001):
  if cad[i] == 0:
    if max(cad[i+1:]) == 0:
      break
    area += height
    continue
  
  if cad[i] <= max(cad[i+1:]) and height < cad[i]:
    height = cad[i]
    area += height
  elif cad[i] > max(cad[i+1:]):
    area += cad[i]
    height = max(cad[i+1:])
  else:
    area += height
print(area)
