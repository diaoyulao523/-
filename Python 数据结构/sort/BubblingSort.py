from CalTime import *
import random

"""
    升序冒泡
    相邻两数比较 如果前面比后面大 则交换两数
    一趟遍历后 从无序区选出最大值 无序区缩小
"""


# 冒泡排序
@calculate_function_run_time_ms
def bubbingSort(value):
    for i in range(len(value) - 1):
        change = False
        for j in range(len(value) - 1 - i):
            if value[j] > value[j + 1]:
                value[j], value[j + 1] = value[j + 1], value[j]
                change = True
        # print(value)
        if not change:
            return


if __name__ == "__main__":
    value = list(range(20))
    random.shuffle(value)
    print("pri: ", value)
    bubbingSort(value)
    print("sorted: ", value)
