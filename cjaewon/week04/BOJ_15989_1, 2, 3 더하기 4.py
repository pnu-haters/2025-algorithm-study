T = int(input()) # T: testcase

"""
dp 점화식이 너무 생각이 안 나서 풀이를 참고함.
dp[n-2][2] 같이 특정한 수를 무조건 사용하게 만드는 경우가 핵심인듯.
"""

dp = [[0 for j in range(4)] for i in range(10001)]

dp[1][2] = 1
dp[2][2] = 2
dp[3][2] = 2
dp[4][2] = 3 

dp[1][3] = 1
dp[2][3] = 2
dp[3][3] = 3
dp[4][3] = 4 

for i in range(4, 10001):
  dp[i][1] = 1
  dp[i][2] = dp[i][1] + dp[i - 2][2]
  dp[i][3] = dp[i][2] + dp[i - 3][3]

for i in range(T):
  n = int(input())
  print(dp[n][3])