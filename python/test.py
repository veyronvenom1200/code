import sys
import decorators
from color import Color

class Maika:
    def __init__(self, func):
        self.func = func

    def __repr__(self):
        return self.__name__

    def __call__(self):
        print("Temp")
        # self.func()
        print("Maika")

@decorators.debug
@decorators.timer
# @Maika
def Tuya():
    print("Tuya")

tuya = Tuya()
Maika(tuya)

# class Series(object):
#     def __init__(self, low, high):
#         self.current = low
#         self.high = high

#     def __iter__(self):
#         return self

#     def __next__(self):
#         if self.current > self.high:
#             raise StopIteration
#         else:
#             self.current += 1
#             return self.current -1

# n_list = Series(1,10)
# print(list(n_list))

def make_list():
    temp_list = []
    def modify_list(num):
        temp_list.append(num)
        return (temp_list, 40)
    return modify_list

a = make_list()
a(4)
b, c = a(5)
print(b, c)


# def concatenate(**words):
#     result = ""
#     print(words[0])
#     for arg in words.keys():
#         result += arg
#     return result

# c = concatenate(1:"Real", 2:"Python", 3:"Is", 4:"Great", 5:"!")
# print(c)

# dictt = {1:"hello"}
# add(5, 6)

MLB_team = {
    'Colorado' : 'Rockies',
    'Boston'   : 'Red Sox',
    'Minnesota': 'Twins',
    'Milwaukee': 'Brewers',
    'Seattle'  : 'Mariners'
}

'Milwaukee' in MLB_team

'Rockies' in MLB_team

'Toronto' not in MLB_team

if __name__ == "__main__": 
    print (f"{Color.PURPLE + Color.BOLD}\"{__file__}\" {Color.END}is being run directly")
else: 
    print (f"{Color.PURPLE + Color.BOLD}\"{__file__}\" {Color.END}is being imported")
