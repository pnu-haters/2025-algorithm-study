import sys

"""
https://en.wikipedia.org/wiki/Linked_list

첫 번째 구현 : list (동적 배열) insert, pop 때문에 시간초과
두 번째 구현 : DoubleLinkedList로 해결
"""

class LinkedListNode:
  def __init__(self, val):
    self.prev = None 
    self.next = None
    self.val = val

text = sys.stdin.readline().rstrip()

head = LinkedListNode(None)
prev = head

cursor = None

for char in text:
  node = LinkedListNode(char)
  node.prev = prev
  node.next = None

  prev.next = node
  prev = node

  cursor = node # 결과적으로 cursor = 마지막 노드

for i in range(int(input())):
  command = sys.stdin.readline().rstrip()

  if command[0] == "P":
    node = LinkedListNode(command[2])

    if cursor.next != None:
      cursor.next.prev = node 
      node.next = cursor.next

    node.prev = cursor
    cursor.next = node

    cursor = node
  elif command[0] == "L":
    if cursor.prev != None:
      cursor = cursor.prev
  elif command[0] == "D":
    if cursor.next != None:
      cursor = cursor.next
  else: # command[0] == "B":
    if cursor.next == None:
      cursor.prev.next = None
      cursor = cursor.prev
    elif cursor.prev == None:
      pass
    else:
      cursor.prev.next = cursor.next
      cursor.next.prev = cursor.prev

      cursor = cursor.prev

curr = head.next
while True:
  print(curr.val, end="")

  if curr.next != None:
    curr = curr.next
  else:
    break
"""
 0 1 2 3
 t e x t
0 1 2 3 4

시간초과 버전

text = list(sys.stdin.readline().rstrip())
cursor = len(text)

for i in range(int(input())):
  command = sys.stdin.readline().rstrip()

  if command[0] == "P":
    add_str = command[2]

    text.insert(cursor, add_str)
    cursor += 1
  elif command[0] == "L":
    if cursor > 0:
      cursor -= 1
  elif command[0] == "D":
    if cursor < len(text):
      cursor += 1
  else: # elif command[0] == "B":
    if cursor > 0:
      text.pop(cursor - 1)
      cursor -= 1

print("".join(text))

text
"""
