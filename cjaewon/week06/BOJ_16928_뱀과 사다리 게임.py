"""
단방향 그래프로 볼 수 있으므로 모든 정점에 대해 최단 거리를 보장하는 bfs를 쓰면 풀 수 있음.
"""

from collections import deque

N, M = map(int, input().split())

ladder = [0 for i in range(101)]
snake = [0 for i in range(101)]

for i in range(N):
  x, y = map(int, input().split())
  ladder[x] = y

for i in range(M):
  u, v = map(int, input().split())
  snake[u] = v

queue = deque([(1, 0)]) # pos, count
visited = [False for i in range(101)]

while queue:
  pos, count = queue.popleft()

  if pos == 100:
    break

  for i in range(1, 7):
    if pos + i <= 100 and not visited[pos + i]:
      visited[pos + i] = True

      if ladder[pos + i] != 0:
        if not visited[ladder[pos + i]]:
          visited[ladder[pos + i]] = True
          queue.append((ladder[pos + i], count + 1))
      elif snake[pos + i] != 0:
        if not visited[snake[pos + i]]:
          visited[snake[pos + i]] = True
          queue.append((snake[pos + i], count + 1))
      else:
        queue.append((pos + i, count + 1))

  
print(count)