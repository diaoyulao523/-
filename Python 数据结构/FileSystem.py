# _*_coding:utf-8_*_
# created by penghao.shi on 2023-07-07 16:21:18


class FileSystem:
    class Node:
        def __init__(self, name: str, type="dir"):
            self.name = name
            self.type = "dir" if type == "dir" else "file"
            self.parent = None
            self.children = []

    def __init__(self):
        self.sep = "/"
        self.root = FileSystem.Node(self.sep)
        self.cur = self.root

    def mkdir(self, name):
        if self.sep not in name:
            name += self.sep
        node = FileSystem.Node(name)
        if not self.exist(node):
            self.cur.children.append(node)
            node.parent = self.cur

    def cd(self, name):
        names = name.split(self.sep)

        for name in names:
            name += self.sep
            if not self.cur:
                return
            if ".." in name:
                self.cur = self.cur.parent
            else:
                for child in self.cur.children:
                    if child.name == name and child.type == "dir":
                        self.cur = child

    def ls(self):
        return "\n".join([child.name for child in self.cur.children])

    def exist(self, node):
        for child in self.cur.children:
            if child.name == node.name and child.type == node.type:
                return True
        return False

    def pwd(self):
        cur = self.cur
        path = []
        while cur:
            path.append(cur.name)
            cur = cur.parent
        path.reverse()
        return "".join(path)



if __name__ == "__main__":
    f = FileSystem()
    f.mkdir("f1")
    f.mkdir("f2")
    print(f.ls())
    f.cd("f1")
    f.mkdir("ff1")
    f.mkdir("ff2")
    f.cd("ff1")
    f.mkdir("fff1")
    f.cd("fff1")
    print("cur dir:", f.pwd())
    print(f.ls())
    f.cd("../../")
    print("cur dir:", f.pwd())
    print(f.ls())


