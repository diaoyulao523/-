# _*_coding:utf-8_*_
# created by penghao.shi on 2023-06-29 09:40:43
from CalTime import *
import random
from MergeSort import *

"""
    桶排序
    将数据范围分为n段 各桶排序， 而后合并
"""


@calculate_function_run_time_ms
def bucketSort(value, bucketNum=10, max=1000):
    bucketList = [[] for _ in range(bucketNum)]

    # 分桶
    bucketLen = max // bucketNum
    for v in value:
        i = (v // bucketLen) if v < max else (bucketNum - 1)  # 大于等于max的元素 桶下标会越界 故全部塞入最后一个桶
        bucketList[i].append(v)

    # 各桶无序 分桶全部完成后 桶内进行一次归并排序
    for bucket in bucketList:
        mergeSort(bucket)

    # 出桶
    index = 0
    for i in bucketList:
        for j in i:
            value[index] = j
            index += 1


if __name__ == "__main__":
    import copy

    value = list(random.randint(0, 1200) for _ in range(10000))
    bucketSort(value)
    print(value)
