# _*_coding:utf-8_*_
# created by penghao.shi on 2023-06-30 11:39:33

var = [[1, 3, 5],
       [6, 7, 9],
       [11, 24, 18]]


def exist(value, target):
    row = len(value)
    if row == 0:
        return False
    col = len(value[0])
    if col == 0:
        return False
    l = 0
    r = row * col - 1
    while l <= r:
        mid = (l + r) // 2  # 中间元素坐标  用来求对应 二维数组中中间元素的行列号
        curValue = value[mid // col][mid % col]
        if curValue == target:
            return True
        elif curValue > target:
            r = mid - 1
        else:
            l = mid + 1
    return False


print(exist(var, 3))
