class Node:
    def __init__(self,prev,item,nxt):
        self.prev = prev
        self.item = item
        self.nxt = nxt

class DLList:
    def __init__(self):
        self.sentinal = Node(None, 63, None)
        self.sentinal.prev = self.sentinal
        self.sentinal.nxt = self.sentinal
    def AddLast(self, item):
        NewLast = Node(None, item, None)
        OldNode = self.sentinal.prev
        OldNode.nxt = NewLast
        NewLast.prev = OldNode
        NewLast.nxt = self.sentinal
        self.sentinal.prev = NewLast
    def RemoveLast(self):
        OldLast = self.sentinal.prev
        NewLast = OldLast.prev
        NewLast.nxt = self.sentinal
        self.sentinal.prev = NewLast

L = DLList()
L.AddLast(5)
L.AddLast(10)
L.AddLast(15)
L.RemoveLast()