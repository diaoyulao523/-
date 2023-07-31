# _*_coding:utf-8_*_
# created by penghao.shi on 2023-06-28 16:58:28
from CalTime import *
import random

'''
 计数排序    限制条件：需要知道取值范围 且需额外开辟内存空间
'''


@calculate_function_run_time_ms
def countSort(value, max=10):
    countList = [0 for _ in range(max + 1)]
    for i in value:
        countList[i] += 1
    i = 0
    for index, count in enumerate(countList):
        for c in range(count):
            value[i] = index
            i += 1


if __name__ == "__main__":
    value = [random.randint(0, 10) for _ in range(200000)]
    print("pri:", value)
    countSort(value)
    print("sorted:", value)
