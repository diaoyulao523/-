# _*_coding:utf-8_*_
# created by penghao.shi on 2023-06-27 11:03:00
from CalTime import *
import random

'''
  了解树 二叉树 完全二叉树 大根堆 小根堆等知识 弄清堆父子节点的下标关系
  排序过程:
  1构造堆  2取堆顶  最后一个叶子节点挪至堆顶  3向下调整使得重新满足堆特性  4 重复2、3 完成排序
'''


def sift(value, low, high):
    '''
    :param value: 数据列表
    :param low:  根节点下标
    :param high: 最后一个叶子节点下标
    :return:
    '''
    p = low
    c = 2 * p + 1
    while c <= high:
        if c + 1 <= high and value[c] < value[c + 1]:
            c += 1
        if value[c] > value[p]:
            value[p], value[c] = value[c], value[p]
            p = c
            c = 2 * p + 1
        else:
            break

@calculate_function_run_time_ms
def heapSort(value):
    high = len(value) - 1
    for i in range((high - 1) // 2, -1, -1):
        sift(value, i, high)
    # print("heap:", value)
    for i in range(high, -1, -1):
        value[0], value[i] = value[i], value[0]
        sift(value, 0, i - 1)


if __name__ == "__main__":
    value = list(range(50000))
    random.shuffle(value)
    print("pri: ", value)
    heapSort(value)
    print("sorted: ", value)
