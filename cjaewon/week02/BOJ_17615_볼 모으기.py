"""
볼을 모으는 최적의 수를 찾는 방법 : 

일단 특정 색을 선택하고 양끝에 무리가 가장 많은 쪽으로 이동시킬 때 이동 횟수를 구하는 코드를 작성함.
그리고 두 색에 대해 최소를 출력

어느정도 직관으로 풀었는데 맞았다...
좋은 방법은 아닌 것 같음..
"""

N = int(input())
seq = input()

min_move = 0

# count red
red_count = seq.count("R")

prefix_red_count = len(seq) - len(seq.lstrip('R')) # thanks to chatgpt
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