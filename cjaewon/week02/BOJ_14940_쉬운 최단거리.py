import sys
from collections import deque

n, m = map(int, input().split()) # n: 세로, m: 가로
area = [list(map(int, sys.stdin.readline().rstrip().split())) for i in range(n)]
min_distance = [[None for j in range(m)] for i in range(n)]

# 아이디어 : 1인 모든 지점에서 2로 가는 걸 계산하는게 아닌 2인 지점에서 다른 모든 지점까지의 거리를 계산한다.
# 어차피 bfs로 퍼져나가면 최단거리라고 생각

start_point = None # 시작 지점 찾기

for i in range(n):
  for j in range(m):
    if area[i][j] == 2:
      start_point = (i, j, 0) # 0은 거리
      break

  if start_point is not None:
    break

min_distance[start_point[0]][start_point[1]] = start_point[2] # = 0

# bfs로 해결

dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]

queue = deque([start_point])

while len(queue) > 0:
  curr = queue.popleft()

  for i in range(4):
    if not (0 <= curr[0] + dy[i] < n and 0 <= curr[1] + dx[i] < m): # 지도 밖의 지점
      continue

    if min_distance[curr[0] + dy[i]][curr[1] + dx[i]] is not None: # 이미 방문한 곳
      continue

    if area[curr[0] + dy[i]][curr[1] + dx[i]] == 0: # 갈 수 없는 곳
      continue

    min_distance[curr[0] + dy[i]][curr[1] + dx[i]] = curr[2] + 1
    queue.append((curr[0] + dy[i], curr[1] + dx[i], curr[2] + 1))


for i in range(n):
  for j in range(m):
    if area[i][j] == 0: # 막혀있는 땅
      print(0, end=" ")
    elif min_distance[i][j] is None: # 도달 할 수 없는 땅
    # (막혀있는 땅, 도달 할 수 없는 땅 모두 0이기 때문에 먼저 area[i][j] == 0인지 확인하여 막혀있는 땅인지 확인하고 아니라면 -> 도달 할 수 없는 땅으로 판단)
      print(-1, end=" ")
    else:
      print(min_distance[i][j], end=" ")
  print()