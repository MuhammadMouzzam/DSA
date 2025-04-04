from node import Node

class SLList: 
    def __init__(self):
        self.first = None
    def AddFirst(self, item):
        self.first = Node(item, self.first)
    def AddLast(self, item):
        tracker = self.first
        if self.first == None:  
            self.first = Node(item, None)
            return None
        while(tracker.nxt != None):
            tracker = tracker.nxt
        tracker.nxt = Node(item, None)
    def GetFirst(self):
        if self.first != None:
            return self.first.item
        print("Empty List")
    def Size(self):
        counter = 0
        tracker = self.first
        if tracker == None:
            print("No Sentinel Node")
            return counter
        while(tracker.nxt != None):
            tracker = tracker.nxt
            counter += 1
        return counter
    def PrintList(self):
        tracker = self.first
        while(tracker != None):
            print(tracker.item, end="-->")
            tracker = tracker.nxt
        print("")
