#!/usr/bin/env python

"""proj11.py is a program that determines the minimum amount of TAs required
for a study session over a certain number of rooms"""

_Author_ = "Nathan Dohm"
_version_ = "3.5.2"
_email_ = "dohmnath@msu.edu"


import itertools


class Matrix(object):
    '''Creates an adjacency matrix in order to determine the minimum amount of
    TAs required for a giving study session over a certain number of rooms.'''

    def __init__(self):  # no modification is needed for this method, but you may modify it if you wish to
        '''Create and initialize your class attributes.'''
        self._matrix = []
        self._rooms = 0

    def read_file(self, fp):  # fp is a file pointer
        '''Build an adjacency matrix that you read from a file fp.'''
        self._matrix = {}
        self.fp = fp
        n = int(self.fp.readline())
        matrix = [[] for _ in range(n)]
        for b in self.fp:
            b = b.strip()
            s = b.index(" ")
            u = b[:s]
            matrix[int(u) - 1].append(v)
            matrix[int(v) - 1].append(u)
        for c in range(1, n + 1):
            self._matrix.update({c: {int(d) for d in ", ".join(matrix[c - 1]).split(',')}})
        return self._matrix, n

    def __str__(self):
        '''Return the matrix as a string.'''
        s = ''
        for (k, v) in self._matrix.items():
            s += "".join(['%s: %s' % (k, " ".join(str(a) for a in v))])
            s += "\n"
        return s  # __str__ always returns a string

    def __repr__(self):  # no modification need of this method
        '''Call __str__() to return a string for displaying in the shell'''
        return self.__str__()

    def adjacent(self, index):
        '''Return the set of connecting rooms to room specified by index'''
        # Hint: only one line, return something, is needed
        return self._matrix[index]

    def rooms(self):
        '''Return the number of rooms'''
        # Hint: only one line, return something, is needed
        return len(self._matrix)


def main():
    '''calculates the minimum of TAs required for a study session and determines
    where they should be placed in order to be able to reach all of the study
    rooms'''
    list_of_rooms = set()
    TAs = 0
    Bool = False
    Sums = 0
    file = input("Enter a file name: ")
    fp = open(file, 'r')
    M = Matrix()
    Matrix_list, Num = M.read_file(fp)
    for n in range(1, Num + 1):  # calculates the sum of all the rooms added together
        Sums += n

    LST = []
    TAs_list = []
    while Bool is False:
        for a in range(1, Num + 1):  # creates the list of rooms
            list_of_rooms.add(a)
        S = set(itertools.combinations(list_of_rooms, TAs))
        set.union(S)
        S = sorted(S)
        for b in S:
            b = list(b)
            LST.append(b)
        for c in LST:
            Total = 0
            Sums_list = []
            for d in c:  # creates a list of the dicitonary keys in the nth tuple of LST, and its values
                for k, v in Matrix_list.items():
                    if d == k:  # attempts to create a coherent list with no two same values
                        if k not in Sums_list:
                            Sums_list.append(k)
                            Total += d
                        for e in v:
                            if e not in Sums_list:
                                Sums_list.append(e)
                                Total += e

            if Total == Sums:  # if the sum of the values in the list and the Sums from earlier are equal, a possible solution is found
                TAs_list.append(c)
                Bool = True

        TAs += 1

    print("TAs needed: " + str(TAs - 1))
    TAs_list = list(map(str, TAs_list[0]))  # througout testing, the first list of the list was the correct answer
    print("TAs assigned to rooms: " + (', '.join(TAs_list)))

    print("\nAdjacency Matrix")
    print(M)


if __name__ == "__main__":
         main()
