from node import Node

class DLList:
    def __init__(self):
        self.first = None
    def AddFirst(self, item):
        tempNode = Node(item, self.first, self.first)
        tempNode.nxt = tempNode
        tempNode.prev = tempNode
        if self.first == None:
            self.first = tempNode
            return None
        tempNode.nxt = self.first
        tempNode.prev = self.first.prev
        self.first.prev.nxt = tempNode
        self.first.prev = tempNode
        self.first = tempNode
    def AddLast(self, item):
        tempNode = Node(item, self.first, self.first)
        tempNode.nxt = tempNode
        tempNode.prev = tempNode
        if self.first == None:
            self.first = tempNode
            return None
        tempNode.nxt = self.first
        tempNode.prev = self.first.prev
        self.first.prev.nxt = tempNode
        self.first.prev = tempNode
    def PrintList(self):
        tracker = self.first
        while(tracker != self.first):
            pass
        

L = DLList()
L.AddFirst('A')
L.AddFirst('B')
L.AddLast('C')