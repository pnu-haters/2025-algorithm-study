import sys
from collections import deque

"""
슬라이싱 윈도우를 이용하여 푸는 문제이다.

sushi를 배열로 할지 딕셔너리로 할 지 고민했는데, 배열로 할 때 초밥 종류의 개수를 셀 때 O(N)이 걸리므로 O(1)이 걸리는 딕셔너리를 선택하였다.
원형인 자료가 나오면 나의 경우에는 주로 deque와 rotate를 사용한다.

벨트에 놓인 회전초밥 개수만 다르고 내용은 같은 문제가 있다.
회전초밥 2 : https://www.acmicpc.net/problem/15961

이 또한 똑같은 코드를 제출하니 풀림.
"""

N, d, k, c = map(int, input().split())
sushi = {}

dq = deque([])

for i in range(N):
 dq.append(int(sys.stdin.readline().rstrip()))

# 슬라이딩 윈도우를 위한 초기 윈도우 설정
for i in range(k):
  if dq[i] in sushi:
    sushi[dq[i]] += 1
  else:
    sushi[dq[i]] = 1

# 최대로 먹을 수 있는 스시의 종류
max_sushi_type = len(sushi.keys())

for i in range(N):

  sushi[dq[0]] -= 1
  if sushi[dq[0]] == 0:
    del sushi[dq[0]]

  if dq[k] not in sushi:
    sushi[dq[k]] = 1
  else:
    sushi[dq[k]] += 1
  
  if c in sushi.keys():
    if max_sushi_type < len(sushi.keys()):
      max_sushi_type = len(sushi.keys())
  else:
    if max_sushi_type < len(sushi.keys()) + 1:
      max_sushi_type = len(sushi.keys()) + 1

  dq.rotate(-1)

print(max_sushi_type)
