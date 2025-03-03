import sys
from collections import deque

n, m, v = map(int, input().split()) # n: 정점의 개수, m: 간선의 개수, v: 시작 정점
graph = [[False for j in range(n + 1)] for i in range(n + 1)] # 정점이 1부터 N까지이므로 n+1 개의 배열을 만들어야 인덱스 N에 접근 가능 

visited_dfs = [False for i in range(n + 1)]
visited_bfs = [False for i in range(n + 1)]

# dfs 재귀함수로 구현
# Mutable Objects의 경우에는 global 키워드를 사용할 필요가 없다.

def dfs(point): 
  visited_dfs[point] = True

  print(point, end=" ")

  for i, connected in enumerate(graph[point]):
    if connected and not visited_dfs[i]:
      dfs(i)
      
# bfs queue로 구현
def bfs():
  queue = deque([v])
  visited_bfs[v] = True

  while len(queue) > 0:
    point = queue.popleft()

    print(point, end=" ")

    for i, connected in enumerate(graph[point]):
      if connected and not visited_bfs[i]:
        visited_bfs[i] = True
        queue.append(i)


for i in range(m):
  a, b = map(int, sys.stdin.readline().rstrip().split())

  graph[a][b] = True
  graph[b][a] = True

dfs(v)
print()
bfs()

