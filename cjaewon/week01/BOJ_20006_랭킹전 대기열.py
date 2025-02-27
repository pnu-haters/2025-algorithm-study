import sys

class Room:
  def __init__(self, level):
    self.level = level
    self.queue = [] # 대기열 not 자료구조

p, m = map(int, input().split())
rooms = [] # 대기열

for i in range(p):
  lev_str, nick = sys.stdin.readline().rstrip().split()
  lev = int(lev_str)    

  is_proper_room_exist = False 

  for room in rooms:
    if len(room.queue) >= m:
      continue
    if room.level - 10 <= lev <= room.level + 10:
      is_proper_room_exist = True
      room.queue.append((lev, nick))
      break
    
  if not is_proper_room_exist: # 방 없을 때 and 적절한 방이 없을 때
    new = Room(lev)
    
    rooms.append(new)
    new.queue.append((lev, nick))

for room in rooms:
  if len(room.queue) == m:
    print("Started!")

    room.queue.sort(key=lambda v: v[1])
    for u in room.queue:
      print(u[0], u[1])
  else:
    print("Waiting!")

    room.queue.sort(key=lambda v: v[1])
    for u in room.queue:
      print(u[0], u[1])
