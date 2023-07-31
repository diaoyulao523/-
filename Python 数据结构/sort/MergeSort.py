# _*_coding:utf-8_*_
# created by penghao.shi on 2023-06-27 16:21:38
from CalTime import *
import random

'''
    拆分而后合并

'''


def merge(value, low, mid, high):
    l = low
    r = mid + 1
    sorted = []
    while l <= mid and r <= high:
        if value[l] < value[r]:
            sorted.append(value[l])
            l += 1
        else:
            sorted.append(value[r])
            r += 1
    while l <= mid:
        sorted.append(value[l])
        l += 1

    while r <= high:
        sorted.append(value[r])
        r += 1
    value[low:high + 1] = sorted


def _mergeSort(value, low, high):
    if low < high:
        mid = (low + high) // 2
        _mergeSort(value, low, mid)
        _mergeSort(value, mid + 1, high)
        merge(value, low, mid, high)


@calculate_function_run_time_ms
def mergeSort(value):
    _mergeSort(value, 0, len(value) - 1)


if __name__ == "__main__":
    value = list(range(50))
    random.shuffle(value)
    print("pri:", value)
    mergeSort(value)
    print("sorted", value)
