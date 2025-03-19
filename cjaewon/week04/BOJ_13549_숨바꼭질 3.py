from collections import deque

# N: 수빈의 위치, K: 동생의 위치
N, K = map(int, input().split())

"""
https://cp-algorithms.com/graph/01_bfs.html
다익스트라의 간소화 버전인 0-1 bfs를 쓰면 풀리는 문제.
"""

dq = deque([(K, 0)]) # (위치, 걸린 시간)
time_cost = {K: 0}

while dq:
  pos, time = dq.popleft()

  if pos == N:
    print(time)
    break

  if pos % 2 == 0:
    choice = [pos // 2, pos - 1, pos + 1]
  else:
    choice = [pos - 1, pos + 1]

  for i, next_pos in enumerate(choice):
    if 0 <= next_pos < 100001 and time_cost.get(next_pos, 2e9) >= time:
      time_cost[next_pos] = time

      if pos % 2 == 0 and i == 0 and pos != 0:
        dq.appendleft((next_pos, time))
      else:
        dq.append((next_pos, time + 1))
      