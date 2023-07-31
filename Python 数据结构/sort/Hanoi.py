# _*_coding:utf-8_*_
# created by penghao.shi on 2023-06-21 16:32:55


from CalTime import *
import sys

print("recursion limit:", sys.getrecursionlimit())  # 打印递归最大深度

"""
 问题描述 汉诺塔
 ​给定三根柱子，记为 A,B,C，其A中柱子上有n个盘子，从上到下编号为1到n，且上面的盘子一定比下面的盘子小。
 问：将A柱上的盘子经由B柱移动到C柱最少需要多少次？

​ 移动时应注意：① 一次只能移动一个盘子
            ②大的盘子不能压在小盘子上
        
    #1. 将前(n-1) 个轮子 由A经过C挪到B
    #2. 将最后一个挪至C
    #3. 将放在B的轮子 由B经过A挪到C
"""


# 递归
@calculate_function_run_time_ms
def hanoi(num):
    _hanoi(num, "A柱", "B柱", "C柱")


def _hanoi(num, a, b, c):
    if num > 0:
        _hanoi(num - 1, a, c, b)
        print("将{}号圆盘 从{}挪到{}".format(num,a, c))
        _hanoi(num - 1, b, a, c)


if __name__ == "__main__":
    hanoi(3)
