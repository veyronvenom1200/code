from math import hypot
from collections import namedtuple

class Vector:
    def __init__(self, x=0, y=0):
        self.x = x
        self.y = y

    def __repr__(self):
        return 'Vector(%r, %r)' % (self.x, self.y)

    def __abs__(self):
        return hypot(self.x, self.y)

    def __bool__(self):
        return bool(abs(self))

    def __add__(self, other):
        x = self.x + other.x
        y = self.y + other.y
        return Vector(x, y)

    def __mul__(self, scalar):
        return Vector(self.x * scalar, self.y * scalar)

# v = Vector(4, 5)
# s = Vector(4, 5)

# print(v+s)

# print(bool(v))

class Args:
    def __init__(self, *args):
        self.args = args
        print(type(self.args))


# c = Args((1,2))

# print(c)

City = namedtuple('City', 'name country population coordinates')

tokyo = City('Tokyo', 'JP', 36.933, (35.689722, 139.691667))

print(f'{tokyo.name:^15} | {tokyo.country:^10}')

print(tokyo)


class Uni:
    def __init__(self, set1):
        self.set1 = set1

    def __getitem__(self, n):
        try:
            new_list = list(self.set1)
            return new_list[n]
        except IndexError as err:
            print(repr(err))

    def __add__(self, other):
        new_set = list(self.set1) + list(other.set1)
        return set(new_set)


    def __iter__(self):
        yield from self.set1

    # def __next__(self):
        # if self.n < len(self.set1):
        #     val = list(self.set1)[self.n]
        #     self.n += 1
        # #     return val
        # # else:
        # #     # self.n = 0
        # #     raise StopIteration

new1 = Uni({1, 2})
new2 = Uni({3, 4})
new3 = new1 + new2

print("Subscript:", new1[3])

for x in new1:
    print(x)

new_set = {3, 4}

print(new_set & new3)

class PowTwo:
    """Class to implement an iterator
    of powers of two"""

    def __init__(self, max=0):
        self.max = max

    def __iter__(self):
        self.n = 0
        return self

    def __next__(self):
        if self.n <= self.max:
            result = 2 ** self.n
            self.n += 1
            return result
        else:
            raise StopIteration

a = [1, 2, 4]

b = a

num = PowTwo(3)
num = iter(num)
print(next(num))

lst = [1, 2, 4, 6, 7]
my_list = [[0]] * 3

my_list[1][0] = 20

print(my_list)

print(lst[0] is lst[3])

lst[2:5] = [100]

print(lst)








