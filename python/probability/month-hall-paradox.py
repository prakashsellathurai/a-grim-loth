import random 
 
class MontyHall:
    def __init__(self):
        self.prize_door = random.randint(1,3)
        self.selected_door = 0
        self.opened_door = 0
 
    def select_door(self):
        self.selected_door = random.randint(1,3)
 
    def host_door(self):
        # host door should not be the selected nor prize door
        d = random.randint(1,3)
        while d == self.selected_door or d == self.prize_door:
            d = random.randint(1,3)
        self.opened_door = d
 
    def switch_door(self):
        # sum of door numbers = 1+2+3 = 6.
        self.selected_door = 6 - self.selected_door - self.opened_door
 
    def hit(self):
        if self.selected_door == self.prize_door:
            return True
 
    def run(self, switch=True):
        self.select_door()
        self.host_door()
        if switch:
            self.switch_door()       
        return self.hit()  # hit?
 
# Switch
RUNS = 10000
print("%s Monty runs" %(RUNS))
hits = 0
for i in range(RUNS):
    monty = MontyHall()
    if monty.run(switch=True):
        hits += 1
print("Switch : %.1f%%" %(100.*hits/RUNS))

# Stay
hits = 0
for i in range(RUNS):
    monty = MontyHall()
    if monty.run(switch=False):
        hits += 1 
print("Stay   : %.1f%%" %(100.*hits/RUNS) )
