# _*_coding:utf-8_*_
# created by penghao.shi on 2023-07-11 11:12:18

class Node:
    def __init__(self, val):
        self.value = val
        self.left = self.right = None


a = Node("A")
b = Node("B")
c = Node("C")
d = Node("D")
e = Node("E")
f = Node("F")
g = Node("G")


"""
二叉树:节点的度至多为2
           E
         /    \
         A     G
          \     \
           C     F
          /  \
         B    D    
"""
root = e
root.left = a
root.right = g
a.right = c
c.left = b
c.right = d
g.right = f


def preOrderTraversal(root):
    if root:
        print(root.value, end=" ")
        preOrderTraversal(root.left)
        preOrderTraversal(root.right)


def inOrderpTraversal(root):
    if root:
        inOrderpTraversal(root.left)
        print(root.value, end=" ")
        inOrderpTraversal(root.right)


def postOrderTraversal(root):
    if root:
        postOrderTraversal(root.left)
        postOrderTraversal(root.right)
        print(root.value, end=" ")


from MyQueue import *


def hTraversal(root):
    myQueue = MyQueue()
    myQueue.push(root)
    while not myQueue.isEmpty():
        node = myQueue.pop()
        print(node.value, end=" ")
        if node.left:
            myQueue.push(node.left)
        if node.right:
            myQueue.push(node.right)


preOrderTraversal(root)
print("\n")
inOrderpTraversal(root)
print("\n")
postOrderTraversal(root)
print("\n")
hTraversal(root)
