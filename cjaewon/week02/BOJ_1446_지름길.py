from collections import deque

N, D = map(int, input().split()) # N: 지름길의 개수 D: 고속도로의 길이
graph = {} # 최대 10,000 ^ 2 인 이차원 배열보다는 dict를 사용하여 메모리 사용량을 줄이자

for i in range(N):
  start, end, shortcut_distance = map(int, input().split())

  if not start in graph:
    graph[start] = [(end, shortcut_distance)]
  else:
    graph[start].append((end, shortcut_distance)) # 단반향이므로 start만 추가

# bfs로 해결하자
# dfs로도 풀 수 있을까? => 재귀로는 힘들수도 +1마다 함수를 실행해야하므로...

queue = deque([(0, 0)]) # (현재 위치, 현재까지 오는데 걸린 거리)
min_distance = 9999999999

while len(queue) > 0:
  curr = queue.popleft()

  if curr[0] == D:
    if curr[1] < min_distance:
      min_distance = curr[1]
    continue
  elif curr[0] > D: # 지름길의 끝이 고속도로의 길이 D를 초과하는 경우가 있는데 그런 케이스는 버려야함 (일반통행이므로! 목적지에 도달하지 못함...)
    continue
  
  if curr[0] in graph:
    for end, shortcut_distance in graph[curr[0]]:
      queue.append((end, curr[1] + shortcut_distance))

  queue.append((curr[0] + 1, curr[1] + 1))

print(min_distance)