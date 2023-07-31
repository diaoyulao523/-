# _*_coding:utf-8_*_
# created by penghao.shi on 2023-06-27 15:31:41

from CalTime import *
from QuickSort import *
import random
import copy

"""
    1. 排序后 取前K个值            nlogn
    2. 冒泡、插入、选择 排序k次     kn
    3. 构造长度为k的小根堆  依次与堆顶比较 大的入堆并调整一次   nlogk
"""


def sift(value, low, high):
    '''
    :param value: 数据列表
    :param low:  根节点下标
    :param high: 最后一个叶子节点下标
    :return:
    '''
    p = low  # 根父节点下标
    tmp = value[p]  # 堆顶值
    c = 2 * p + 1  # 左孩子下标
    while c <= high:  # 存在叶子节点
        if (c + 1 <= high) and value[c + 1] < value[c]:  # 取最小孩子 （存在右孩子、且右孩子比左孩子大）
            c += 1
        if value[c] < tmp:  # 最小孩子大于堆顶  最小孩子与堆顶交换位置 堆顶继续往下找合适位置
            value[p] = value[c]
            p = c
            c = 2 * p + 1
        else:
            value[p] = tmp  # 堆顶值下放到某一级非叶子节点
            break
    value[p] = tmp  # 堆顶值 放到叶子节点

@calculate_function_run_time_ms
def topK1(value, k):
    quickSort(value)
    return value[-k:][::-1]


@calculate_function_run_time_ms
def topK3(value, k):
    # 取前K个数 构造小根堆
    data = value[:k]
    for i in range((k - 2) // 2, -1, -1):
        sift(data, i, k - 1)

    # 遍历 入堆
    for i in range(k, len(value)):
        if value[i] > data[0]:
            data[0] = value[i]
            sift(data, 0, k - 1)
    # 出数
    for i in range(k - 1, -1, -1):
        data[0], data[i] = data[i], data[0]
        sift(data, 0, i - 1)
    return data


if __name__ == "__main__":
    value1 = list(range(100000))
    random.shuffle(value1)
    value2 = copy.deepcopy(value1)
    value3 = copy.deepcopy(value1)
    # print("pri: ", value1)

    print(topK1(value1, 100))

    print(topK3(value3, 100))
