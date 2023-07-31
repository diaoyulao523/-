# _*_coding:utf-8_*_
# created by penghao.shi on 2023-06-21 13:53:00
from CalTime import *
import random

"""
    升序插入
    无序区第一个数与有序区元素 从大到小依次比较， 若有序区元素大于该数 则该有序区右挪 该数与有序区下一元素比较
    直至在有序区找到某一数值小于该元素 在该元素后插入
"""


# 插入排序
@calculate_function_run_time_ms
def insertSort(value):
    for curIndex in range(1, len(value)):
        insertIndex = curIndex - 1
        cur = value[curIndex]
        while value[insertIndex] > cur and insertIndex >= 0:
            value[insertIndex+1] = value[insertIndex]
            insertIndex -= 1
        value[insertIndex+1] = cur





if __name__ == "__main__":
    value = list(range(5000))
    random.shuffle(value)
    print("pri: ", value)
    insertSort(value)
    print("sorted: ", value)
