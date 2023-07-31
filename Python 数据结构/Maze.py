# _*_coding:utf-8_*_
# created by penghao.shi on 2023-07-04 10:11:23
from Stack import *
from MyQueue import *

'''
 迷宫问题求解
 1 深度优先搜索 DFS  -栈
 2 广度优先搜索 BFS  -队列
 
'''
MAZE = [
    [1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
    [1, 0, 0, 0, 1, 1, 0, 1, 1, 1],
    [1, 1, 1, 0, 0, 0, 0, 1, 1, 1],
    [1, 0, 0, 0, 1, 0, 1, 1, 1, 1],
    [1, 0, 1, 1, 1, 1, 0, 0, 0, 1],
    [1, 0, 0, 0, 0, 0, 0, 1, 1, 1],
    [1, 1, 0, 0, 1, 1, 1, 1, 1, 1],
    [1, 1, 1, 0, 0, 0, 1, 1, 1, 1],
    [1, 1, 1, 1, 1, 0, 0, 0, 0, 1],
    [1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
]

dirs = [
    lambda x, y: (x + 1, y),
    lambda x, y: (x, y - 1),
    lambda x, y: (x - 1, y),
    lambda x, y: (x, y + 1),

]


def maze_DFS(Sx, Sy, Tx, Ty):
    stack = Stack()
    stack.push((Sx, Sy))
    while not stack.isEmpty():
        cur = stack.top()
        if cur[0] == Tx and cur[1] == Ty:  # 找到终点 依次打印输出
            path = []
            while not stack.isEmpty():  # 依次出栈 由于反序 所以调用一次reverse
                path.append(stack.pop())
            path.reverse()
            print(path)  # 打印路径
            for i in MAZE:
                print(i)
            return True

        allUnvalid = True
        for dir in dirs:  # 遍历四个方向
            next = dir(cur[0], cur[1])
            if MAZE[next[0]][next[1]] == 0:
                stack.push(next)
                MAZE[next[0]][next[1]] = 9  # 已走过
                allUnvalid = False
                break
        if allUnvalid:  # 四个方向都不能走
            MAZE[cur[0]][cur[1]] = 9  # 已走过
            stack.pop()

    print("无解")
    return False


def maze_BFS(Sx, Sy, Tx, Ty):  # 最短路径
    queue = MyQueue()  # 队列只存路径的最终节点
    queue.push((Sx, Sy, -99))  # 起点入队列  元组第一个元素记录 行号， 第二个元素记录列号 第三个元素记录上一步路在队列中的下标

    allStep = []
    while not queue.isEmpty():
        cur = queue.pop()
        if cur[0] == Tx and cur[1] == Ty:  # 找到终点 依次打印输出
            path = []
            index = cur[2]
            while index != -99:
                step = allStep[index]
                path.append((step[0], step[1]))
                index = step[2]
            path.append((Sx, Sy))  # 添加起点
            path.reverse()
            print(path)  # 打印路径
            return True

        for dir in dirs:
            next = dir(cur[0], cur[1])
            if MAZE[next[0]][next[1]] == 0:
                allStep.append((next[0], next[1], cur[2]))
                queue.push((next[0], next[1], len(allStep) - 1))
                MAZE[next[0]][next[1]] = 9  # 已走过
    print("无解")
    return False


if __name__ == "__main__":
    maze_DFS(1, 1, 8, 8)
