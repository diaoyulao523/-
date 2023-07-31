# _*_coding:utf-8_*_
# created by penghao.shi on 2023-06-29 13:56:31
from CalTime import *
import random
from MergeSort import *
import math

'''
多关键字排序:例如 按年龄和工资对员工排序  先按年龄排好序后， 再按工资对相同年龄的做一次稳定排序（使用稳定排序的意义在于不破坏第一个排序条件）
基数排序
  按位分桶  比完个位 再比十位 每一轮使用桶排序
'''


# def maxBit(value):  # 找列表中最大数有多少位
#     max = value[0]
#     for i in range(1, len(value)):
#         if value[i] > max:
#             max = value[i]
#     bit = 0
#     while max >= 10 ** bit:
#         bit += 1
#     return bit


def maxBit(value):
    maxv = max(value)
    return math.floor(math.log(maxv, 10) + 1)


@calculate_function_run_time_ms
def radixSort(value):
    maxBitNum = maxBit(value)

    for b in range(maxBitNum):  # 每一位进行一轮桶排序
        buckets = [[] for _ in range(10)]  # 创建10个桶
        for v in value:
            index = (v // 10 ** b) % 10  # 第b位数上的值 判定其放入哪个桶  例如985 b=0 index=5  b=1 index=8  b=2 index=9
            buckets[index].append(v)

        value.clear()
        for bucket in buckets:  # 某一位保持有序后 数据写回 对高一位在进行一次排序
            value.extend(bucket)


if __name__ == "__main__":
    value = [random.randint(1, 1000) for _ in range(500000)]
    print("最大位数", maxBit(value))
    radixSort(value)
    print(value, len(value))