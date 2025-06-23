
l = [0, 1, 2, 6, 7, 7]

while len(l) < 10000:
    l.append(l[-1] + 1)
    l.append(l[-1] - 2)
    l.append(l[-1] + 3)
    l.append(l[-1] + 2)

class Solution(object):
    def clumsy(self, n):

        return l[n]