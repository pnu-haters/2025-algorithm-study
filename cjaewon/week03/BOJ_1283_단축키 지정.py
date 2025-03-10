"""
문제는 쉬운데 구현하기가 까다로움.
"""

N = int(input())
shortcut = {}

for i in range(N):
  option = input()
  pos = None

  # 단어 첫 글자가 단축키 지정되었는지 확인하고 지정 안되었으면 저장하고 인덱스도 pos에 저장
  for i, char in enumerate(option):
    if not (i == 0 or option[i - 1] == " "): continue
    if char.lower() in shortcut: continue

    shortcut[char.lower()] = True
    pos = i
    break
  
  # 단어 첫 글자를 단축키 지정에 성공했으면 그냥 출력
  if pos is not None:
    for i, char in enumerate(option):
      if i == pos:
        print(f"[{char}]", end="")
      else:
        print(char, end="")
    print()

    continue

  # 단어 첫 글자 단축키 지정에 실패했으면 순차적으로 다음 문자에 대해 판단하기 
  for i, char in enumerate(option):
    # 단축키에 지정되어 있거나, 이미 해당 옵션에 대한 단축키가 추가되었거나, 스페이스바이면 그냥 출력
    # 단어 첫 글자를 단축키 지정에 실패했을 때 실행되므로 굳이 단어 첫 글자인지 판단 할 필요가 없음 판단이 char.lower() in shortcut에 포함됨

    if char.lower() in shortcut or pos is not None or char == " ":
      print(char, end="")
    else:
      shortcut[char.lower()] = True
      pos = i
      print(f"[{char}]", end="")

  print()