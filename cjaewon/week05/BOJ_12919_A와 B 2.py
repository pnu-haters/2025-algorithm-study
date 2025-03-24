"""
1. 첫 번째 시도
정추적 dfs 작성하였지만 2^49의 경우의 수 때문에 시간초과.

2. 두 번째 시도
여전히 정추적으로 가도록 구현.
다만 T의 A_count, B_count 를 이용하여 개수를 초과할때 그 케이스를 버리도록 함.
여전히 시간초과

3. 세 번째 시도
역추적으로 구현함. 경우의 수가 약 2^20이 되기 때문에 풀리는 것으로 보임.
"""

S = input()
T = input()

def dfs(curr):
  if len(S) > len(curr): return

  if S == curr:
    print(1)
    exit()

  if curr[0] == "B":
    dfs(curr[::-1][:-1])
  
  if curr[-1] == "A":
    dfs(curr[:-1])
    
dfs(T)

print(0)