# _*_coding:utf-8_*_
# created by penghao.shi on 2023-06-30 16:27:15

class Stack:

    def __init__(self):
        self.stack = []

    def push(self, e):
        self.stack.append(e)

    def pop(self):
        if len(self.stack) > 0:
            return self.stack.pop()
        else:
            return None

    def isEmpty(self):
        return len(self.stack) == 0

    def top(self):
        return self.stack[-1]



# 括号匹配问题
def bracketsMatch(str):
    matchdict = {"{": "}", "[": "]", "(": ")", "<": ">"}
    stack = Stack()
    for c in str:
        if c not in matchdict.keys() or c not in matchdict.values():
            continue
        if stack.isEmpty():
            stack.push(c)
        elif matchdict[stack.top()] == c:
            stack.pop()
        else:
            stack.push(c)
    return stack.isEmpty()


if __name__ == "__main__":
    str = "[{(bb)[a]}]"
    print(bracketsMatch(str))
