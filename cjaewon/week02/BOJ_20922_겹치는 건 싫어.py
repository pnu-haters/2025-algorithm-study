n, k = map(int, input().split()) # n: 수열의 개수 k: 중복 허용 수
arr = list(map(int, input().split()))

count = {}

# n이 20만이므로 시간 초과가 나지 않도록 주의해야함
# 어떤 방식으로 접근해야할까
# 무지성으로 품...
# 어떤 숫자가 특정 개수를 초과할 시 그 숫자가 처음 나오는 곳으로 이동한 후 한 칸 이동해서 다시 갯수 세기 반복

i = 0
length = 0
max_length = 0

while i < n:
  if arr[i] in count:
    count[arr[i]][0] += 1
    if count[arr[i]][0] > k:
      i = count[arr[i]][1] + 1
      count = {}
      length = 0
      continue
  else:
    count[arr[i]] = [1, i] # 수의 중복 개수, 수의 가장 최근 index

  length += 1
  i += 1

  if length > max_length:
    max_length = length

print(max_length)


