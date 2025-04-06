"""
알고리즘 분류에는 슬라이딩 윈도우라고 되어있는데, 왜 슬라이딩 윈도우인지는 잘 모르겠다.

최소, 최대 문자열의 모두 시작점과 끝점이 무조건 같아야한다는 사실을 발견함.

처음에는 이중 for문을 이용하여 풀었더니 시간 초과가 떠서
미리 전처리를 해주고 for문을 돌리는 코드를 작성하니 시간 안에 풀 수 있었다.
"""

import sys
from collections import defaultdict

T = int(input()) # T: testcase

for i in range(T):
  W = sys.stdin.readline().rstrip()
  K = int(input())

  # K=1 일 때는 특수 케이스이므로 처리
  if K == 1:
    print(1, 1)
    continue
  
  min_len = float('inf')
  max_len = -float('inf')

  # 전처리를 하자.
  # 미리 특정 문자열에 대한 index를 모두 저장해두자.
  pos = defaultdict(list)

  for i, c in enumerate(W):
    pos[c].append(i)

  for i in range(len(W)):
    # 살짝 복잡함.
    # 대충 찍고 실행하면서 index 맞췄음.
    if len(pos[W[i]]) - (pos[W[i]].index(i)) < K: continue

    min_len = min(min_len, pos[W[i]][pos[W[i]].index(i) + K - 1] - i + 1)
    max_len = max(max_len, pos[W[i]][pos[W[i]].index(i) + K - 1] - i + 1)

  if min_len == float('inf') or max_len == -float('inf'): # 사실 하나만 체크해도 상관없음.
    print(-1)
  else:
    print(min_len, max_len)