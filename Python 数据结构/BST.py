# _*_coding:utf-8_*_
# created by penghao.shi on 2023-07-11 14:46:40
import sys

# sys.setrecursionlimit(10000)
print("recursion limit:", sys.getrecursionlimit())  # 打印递归最大深度

'''
二叉搜索树特征:满足二叉树的基础上， 节点的左节点值 永远小于该节点的值  节点的右节点值 永远大于该节点d的值
'''
from collections import deque
from MyQueue import *

class Node:
    def __init__(self, val):
        self.value = val
        self.parent = self.left = self.right = None


class BST:
    def __init__(self, values=None):
        self.root = None
        if values:
            for val in values:
                self.insert(val)

    def insert(self, val):
        p = self.root
        if not p:
            self.root = Node(val)
        else:
            while p:
                if val < p.value:
                    if p.left:
                        p = p.left
                    else:
                        p.left = Node(val)
                        p.left.parent = p
                        break
                elif val > p.value:
                    if p.right:
                        p = p.right
                    else:
                        p.right = Node(val)
                        p.right.parent = p
                        break
                else:  # val == p.val  #树中已存在该元素
                    break

    def insert_rec(self, val, node):
        if not node:
            node = Node(val)
            if not self.root:
                self.root = node
        elif val < node.value:
            node.left = self.insert(val, node.left)
            node.left.parent = node
        elif val > node.value:
            node.right = self.insert(val, node.right)
            node.right.parent = node
        return node

    def query(self, val):
        node = None
        p = self.root
        while p:
            if val < p.value:
                p = p.left
            elif val > p.value:
                p = p.right
            else:
                node = p
                break
        return node

    def query_rec(self, val, node):
        if not node:
            pass
        elif val < node.value:
            node = self.query_rec(val, node.left)
        elif val > node.value:
            node = self.query_rec(val, node.right)
        return node

    def __delLeafNode(self, node):
        if not node.parent:
            self.root = None
        elif node.value > node.parent.value:
            node.parent.right = None
        else:
            node.parent.left = None

    def __delOnlyLeftNode(self, node):
        if not node.parent:
            self.root = node.left
        elif node.value > node.parent.value:
            node.parent.right = node.left
            node.left.parent = node.parent
        else:
            node.parent.left = node.left
            node.left.parent = node.parent

    def __delOnlyRightNode(self, node):
        if not node.parent:
            self.root = node.left
        elif node.value > node.parent.value:
            node.parent.right = node.right
            node.right.parent = node.parent

        else:
            node.parent.left = node.right
            node.right.parent = node.parent

    def delete(self, val):
        node = self.query(val)
        if not node:
            print("value:{} not in BST".format(val))
            return
        if not node.left and not node.right:  # 无子节点
            self.__delLeafNode(node)
        elif not node.right:  # 仅有左节点
            self.__delOnlyLeftNode(node)
        elif not node.left:  # 仅有右节点
            self.__delOnlyRightNode(node)
        else:  # 左右节点均存在， 从右子树一直往左找 直到叶子节点 将其挪过来
            minNode = node.right
            while minNode.left:
                minNode = minNode.left
            if minNode.right:
                self.__delOnlyRightNode(minNode)
            else:
                self.__delLeafNode(minNode)
            node.value = minNode.value

    def preOrderpTraversal(self, root, orderList):  # 先序遍历
        if root:
            orderList.append(root.value)
            self.preOrderpTraversal(root.left, orderList)
            self.preOrderpTraversal(root.right, orderList)
        return orderList

    def inOrderpTraversal(self, root, orderList):  # 中序遍历保证有序
        if root:
            self.inOrderpTraversal(root.left, orderList)
            orderList.append(root.value)
            self.inOrderpTraversal(root.right, orderList)
        return orderList

    def postOrderpTraversal(self, root, orderList):  # 后续遍历
        if root:
            self.postOrderpTraversal(root.left, orderList)
            self.postOrderpTraversal(root.right, orderList)
            orderList.append(root.value)
        return orderList

    def hOrderpTraversal(self, root, orderList):  # 后续遍历
        myQueue = MyQueue()
        myQueue.push(root)
        while not myQueue.isEmpty():
            node = myQueue.pop()
            orderList.append(node.value)
            if node.left:
                myQueue.push(node.left)
            if node.right:
                myQueue.push(node.right)
        return orderList


if __name__ == "__main__":
    import random

    values = [_ for _ in range(20)]

    for i in range(100):
        random.shuffle(values)
        print("原数据", values)
        T = BST(values)
        orderList = []
        T.delete(6)

        orderList.clear()
        T.preOrderpTraversal(T.root, orderList)
        print("先序遍历:", orderList)

        orderList.clear()
        T.inOrderpTraversal(T.root, orderList)
        print("中序遍历:", orderList)

        orderList.clear()
        T.postOrderpTraversal(T.root, orderList)
        print("后序遍历:", orderList)

        orderList.clear()
        T.hOrderpTraversal(T.root, orderList)
        print("层次遍历:", orderList)
        print(" ")
