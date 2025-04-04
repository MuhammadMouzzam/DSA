from SLList import SLList


L = SLList()
L.PrintList()
L.AddFirst('A')
L.PrintList()
L.AddFirst('B')
L.PrintList()
L.AddLast('C')
L.PrintList()
L.AddLast('B')
L.PrintList()
L.AddFirst('D')
L.PrintList()
print(L.GetFirst())
print(L.Size())
print(L.GetFirst())
print(L.Size())