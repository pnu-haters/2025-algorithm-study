import time
from collections import deque

class Belt:
  def __init__(self, durability, robot_on = False):
    self.durability = durability
    self.robot_on = robot_on

class ConveyorBelt:
  def __init__(self, belts: list[Belt], N: int, K: int):
    self.belts = deque(belts)
    self.N = N
    self.K = K
    self.count = 1

  def do_set(self):
    while True:
      self.rotate_belt()
      self.move_robots()
      self.raise_robot()

      if not self.ok():
        return self.count

      self.count += 1 

  def rotate_belt(self):
    self.belts.rotate(1)

    if self.belts[self.N - 1].robot_on:
      self.belts[self.N - 1].robot_on = False

  def move_robots(self):
    for i in range(self.N, 1, -1):
      if self.belts[i - 1].robot_on and not self.belts[i].robot_on and self.belts[i].durability > 0:
        self.belts[i - 1].robot_on = False
        self.belts[i].robot_on = True
        self.belts[i].durability -= 1
    
    if self.belts[self.N - 1].robot_on:
      self.belts[self.N - 1].robot_on = False

  def raise_robot(self):
    if self.belts[0].durability > 0:
      self.belts[0].robot_on = True
      self.belts[0].durability -= 1

  def ok(self):
    if sum(1 for b in self.belts if b.durability <= 0) >= self.K:
      return False
    return True


N, K = map(int, input().split())
durabilities = list(map(int, input().split()))

conveyor_belt = ConveyorBelt([Belt(dur) for dur in durabilities], N, K)

print(conveyor_belt.do_set())
