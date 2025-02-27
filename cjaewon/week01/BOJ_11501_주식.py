import sys

def predict():
  sys.stdin.readline()
  prices = list(map(int, sys.stdin.readline().rstrip().split()))
  max_price = 0
  result_sum = 0

  for price in reversed(prices):
    if price > max_price:
      max_price = price
    else:
      result_sum += max_price - price

  print(result_sum)


for i in range(int(input())):
  predict()

"""
최대 이익을 계산하는 방법 => 앞에 자신보다 높은 가격이 있으면 무조건 사고, 가장 비쌀 때 판다.

선택지 : 3개 1. 산다 2. 판다 3. 아무것도 하지 않는다.
최대 이익을 얻는 방법은 앞에 자신보다 높은 가격이 있으면 사고 그 가격에 판다.

시간초과 코드 (pypi 83%)

def predict():
  n = int(input())
  sum = 0
  prices = list(map(int, sys.stdin.readline().rstrip().split()))
  m, midx = 0, 0

  for i in range(n):
    if m < prices[i]:
      m = prices[i]
      midx = i

  for i in range(n):
    if i == midx:
      m = 0
      midx = 0
      for j in range(i + 1, n):
        if m < prices[j]:
          m = prices[j]
          midx = j
    else:
      sum += m - prices[i]

  print(sum)

testcase = int(input())

for i in range(testcase):
  predict()
"""