"""
슬라이싱 윈도우를 이용하여 푸는 문제이다.

먼저 aabbaaabaaba를 입력받았다고 해보자.
aabbaaabaaba에서 a는 8개, b는 4개

a부터 계산해보자.

입력받은 aabbaaabaaba에 대해 반복문을 돌려 각각의 인덱스를 포함한 8개를 윈도우에 대해 계산한다.
처음으로 인덱스가 1인 경우에는 윈도우 안에 aabbaaab이 포함된다. 

여기서는 모두 a로 만들기 위해 필요한 교환 개수는 3이다.
이를 계속 반복하면 a의 경우 최소 교환 개수를 구할 수 있다.

마찬가지로 b 또한 계산해서 a와 b를 비교하여 최소를 구해준다.

원형 배열를 위해 deque를 사용하고 rotate 함수를 이용하여 돌려주었다.
"""

from collections import deque

chars = list(input())
dq = deque(chars)

a_window = chars.count("a")
b_window = chars.count("b")

min_swap = 1e9

for i in range(len(chars)):
  swap_count = 0

  for j in range(a_window):
    if dq[j] != "a":
      swap_count += 1

  if min_swap > swap_count:
    min_swap = swap_count

  dq.rotate(1)

for i in range(len(chars)):
  swap_count = 0

  for j in range(b_window):
    if dq[j] != "b":
      swap_count += 1

  if min_swap > swap_count:
    min_swap = swap_count

  dq.rotate(1)

print(min_swap)