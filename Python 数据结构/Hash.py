# _*_coding:utf-8_*_
# created by penghao.shi on 2023-07-07 10:39:50
from LinkList import *

"""
拉链法 模拟简单哈希表
"""


class HashTable:
    def __init__(self, size=10):
        self.size = size
        self.T = [LinkList() for _ in range(size)]

    def h(self, value):    # 哈希函数，返回元素在T中的坐标
        return value % self.size

    def append(self, value):
        if not self.find(value):
            index = self.h(value)
            self.T[index].append(value)
        else:
            print("{0} 已存在!".format(value))

    def find(self, value):
        index = self.h(value)
        return self.T[index].find(value)

    def __repr__(self):
        return ", ".join(map(str, self.T))


if __name__ == "__main__":
    H = HashTable()
    H.append(0)
    H.append(10)
    H.append(100)

    H.append(2)
    H.append(12)
    print(H)


