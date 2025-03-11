from collections import deque

N, K = map(int, input().split()) # N: 수빈 위치, K: 동생 위치
q = deque([(N, 0)]) # (수빈 위치, 찾는데 걸린 시간)
min_find_time = 1e9 

visited = [False for i in range(100001)]
visited[N] = True

while q:
  curr = q.popleft()

  if curr[0] == K:
    if curr[1] < min_find_time:
      min_find_time = curr[1]
      continue
  
  if curr[0] + 1 <= 100000 and not visited[curr[0] + 1]:
    visited[curr[0] + 1] = True
    q.append((curr[0] + 1, curr[1] + 1))
  if curr[0] - 1 >= 0 and not visited[curr[0] - 1]:
    visited[curr[0] - 1] = True
    q.append((curr[0] - 1, curr[1] + 1))
  if curr[0] * 2 <= 100000 and not visited[curr[0] * 2]:
    visited[curr[0] * 2] = True
    q.append((curr[0] * 2, curr[1] + 1))

  
print(min_find_time)

