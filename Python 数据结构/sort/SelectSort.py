# _*_coding:utf-8_*_
# created by penghao.shi on 2023-06-21 13:51:10
from CalTime import *
import random

"""
    升序选择
    从无序区选出一个最小值，与当前元素交换位置 
"""


# 选择排序
@calculate_function_run_time_ms
def selectSort(value):
    for i in range(len(value)-1):
        minInidex = i
        for j in range(i+1,len(value)):
            if value[j] < value[minInidex]:
                minInidex = j
        value[i], value[minInidex] = value[minInidex], value[i]







if __name__ == "__main__":
    value = list(range(20))
    random.shuffle(value)
    print("pri: ", value)
    selectSort(value)
    print("sorted: ", value)
