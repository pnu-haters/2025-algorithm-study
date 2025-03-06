"""
볼을 모으는 최적의 수를 찾는 방법 : 

일단 특정 색에 관해서 최적의 이동 횟수는 양끝에 (같은 색깔) 무리가 가장 큰 쪽으로 가장 가까운데 부터 이동시킬 때 횟수라고 판단함.
따라서 파란 빨간 모두 구해주고 최소를 구하고 출력하게함

어느정도 직관으로 풀었는데 맞았다...
좋은 방법은 아닌 것 같음..
"""

N = int(input())
seq = input()

min_move = 0

# count red
red_count = seq.count("R")

# thanks to chatgpt.
# pre/sufffix 세는 함수가 있는지 궁금해서 물어봤는데 이런 코드를 받음
prefix_red_count = len(seq) - len(seq.lstrip('R'))
suffix_red_count = len(seq) - len(seq.rstrip('R'))

if prefix_red_count > suffix_red_count:
  min_move = red_count - prefix_red_count
else:
  min_move = red_count - suffix_red_count

# count blue
blue_count = seq.count("B")

prefix_blue_count = len(seq) - len(seq.lstrip('B')) # thanks to chatgpt
suffix_blue_count = len(seq) - len(seq.rstrip('B'))

if prefix_blue_count > suffix_blue_count:
  min_move = min(min_move, blue_count - prefix_blue_count)
else:
  min_move = min(min_move, blue_count - suffix_blue_count)

print(min_move)