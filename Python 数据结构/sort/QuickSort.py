# _*_coding:utf-8_*_
# created by penghao.shi on 2023-06-21 17:22:01
from CalTime import *
import random

"""
  分区：随机选择一个数作为基础准值， 将数据拆分为两组  left组内元素均小于该数  right组内元素均大于该元素
  递归左右子区

"""


# 方法1 原地排序 无需额外申请内存
@calculate_function_run_time_ms
def quickSort(value):
    _quickSort(value, 0, len(value) - 1)


def _quickSort(value, left, right):
    if left < right:
        mid = partation(value, left, right)
        _quickSort(value, 0, mid - 1)
        _quickSort(value, mid + 1, right)


def partation(value, left, right):
    ref = value[left]
    while left < right:
        if left < right and value[right] > ref:
            right -= 1
        value[left] = value[right]
        if left < right and value[left] < ref:
            left += 1
        value[right] = value[left]
    value[left] = ref

    return left


# 方法2 开辟额外空间排序
@calculate_function_run_time_ms
def quickSort2(value):
    return _quickSort2(value)


def _quickSort2(value):
    if len(value) < 2:
        return value
    ref = value[0]
    l, r = [], []
    value.remove(ref)
    for i in value:
        if i > ref:
            r.append(i)
        else:
            l.append(i)
    return _quickSort2(l) + [ref] + _quickSort2(r)


if __name__ == "__main__":
    value = list(range(5))
    random.shuffle(value)
    print("pri: ", value)
    quickSort(value)
    print("sorted: ", value)
