from array import array as arr

class Adeque:
    def __init__(self):
        self.item = arr('i', [0 for x in range(8)])
        self.NextFirst = 3
        self.NextLast = 4
        self.currentsize = 0
        self.start = 0
        # self.
    def AddLast(self, item):
        self.item[self.NextLast] = item
        self.NextFirst += 1


a = Adeque()
print(a.item)