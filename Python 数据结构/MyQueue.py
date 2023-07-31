# _*_coding:utf-8_*_
# created by penghao.shi on 2023-06-30 17:42:00


class MyQueue:

    def __init__(self, size=10):
        self.size = size
        self.start = 0  # 队首 出队列
        self.end = 0  # 队尾 进队列
        self.queue = [None for _ in range(size)]

    def push(self, e):
        if self.isFull():   # 队满 则翻倍扩容
            self.queue.extend([None for _ in range(self.size)])
            self.size += self.size

        self.end = (self.end + 1) % self.size
        self.queue[self.end] = e
        return e

    def pop(self):
        if self.isEmpty():
            raise IndexError("queue is empty.")
        self.start = (self.start + 1) % self.size
        r = self.queue[self.start]
        self.queue[self.start] = None
        return r

    def isEmpty(self):
        return self.start == self.end

    def isFull(self):
        return (self.end + 1) % self.size == self.start


if __name__ == "__main__":
    q = MyQueue(10)
    for i in range(10):
        q.push(i)
        print(q.pop())


