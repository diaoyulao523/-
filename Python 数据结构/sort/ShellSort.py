# _*_coding:utf-8_*_
# created by penghao.shi on 2023-06-28 16:06:40
from CalTime import *

'''
    希尔排序： 一种分组插入排序
    思路：取d1 = n//2   n为元素个数 将元素分为d1段 各段进行插入排序，d2 = d1 //2  将元素分为d2段 各段进行插入排序 直至dx = 1 做一次全元素插入排序
'''

import random


def insertSortGap(value, gap):
    for i in range(gap, len(value)):
        l = i - gap
        tmp = value[i]
        while l >= 0 and value[l] > tmp:
            value[l + gap] = value[l]
            l -= gap
        value[l + gap] = tmp

@calculate_function_run_time_ms
def shellSort(value):
    gap = len(value) // 2
    while gap >= 1:
        insertSortGap(value, gap)
        gap //= 2


if __name__ == "__main__":
    value = list(range(10000))
    random.shuffle(value)
    # print("pri:", value)
    shellSort(value)
    # print("sorted:", value)
