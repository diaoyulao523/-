# _*_coding:utf-8_*_
# created by penghao.shi on 2023-07-05 15:55:05
"""
 尾插法实现单向链表    支持添加、删除、查找、打印 、迭代
"""
class LinkList:
    class Node:
        def __init__(self, item):
            self.item = item
            self.next = None

    class LinkListIterator:
        def __init__(self, item):
            self.item = item

        def __next__(self):
            if self.item:
                it = self.item
                self.item = self.item.next
                return it.item
            else:
                raise StopIteration

        def __iter__(self):
            return self




    def __init__(self, values = None):
        self.head = self.tail = None
        if values:
            self.extend(values)

    def extend(self, values):
        for var in values:
            self.append(var)

    def append(self, value):
        next = LinkList.Node(value)
        if self.head:
            self.tail.next = next
            self.tail = next
        else:
            self.head = next
            self.tail = self.head

    def remove(self, value):
        lastNode = None
        curNode = self.head
        while curNode:
            if curNode.item == value:
                if curNode is self.head:
                    self.head = curNode.next
                elif curNode is self.tail:
                    self.tail = lastNode
                    lastNode.next = None
                else:
                    lastNode.next = curNode.next
                break
            lastNode = curNode
            curNode = curNode.next

    def find(self, value):
        exist = False
        try:
            for v in self:
                if v == value:
                    exist = True
        except StopIteration as ex:
            pass
        return exist

    def __iter__(self):
        return LinkList.LinkListIterator(self.head)

    def __repr__(self):
        return "<" + ",".join(var for var in map(str, self)) + ">"


if __name__ == "__main__":
    L = LinkList([1, 2, 3, 4, 5, 6])

    for l in L:
        print(l)

    print(L.find(1))
    print(L.find(1))
    print(L.find(4))
    print(L.find(7))

    L.remove(1)
    print(L)
    L.remove(8)
    print(L)
    L.remove(6)
    print(L)
    L.remove(4)
    print(L)
