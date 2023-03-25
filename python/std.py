import os
import re
import pyperclip

# 101543018846

with open('t1.txt', 'r') as f:
    read_data = f.read()

print(read_data)

phone_num_regex = re.compile(r'(\d{3})-(\d{3}-\d{4})')
# day_of_week = re.compile(r'(sun|mon|tues|wednes|thurs|fri|satur)day', re.IGNORECASE)
day_of_week = re.compile(r'day')

#re.sub() returns a string
read_data = day_of_week_str = re.sub(day_of_week, 'awesome', read_data)
print(day_of_week_str)
mo = phone_num_regex.search(read_data)
# day = day_of_week.findall(day)

print('Phone number found: ' + mo.group(1))
print(read_data)

areaCode, mainNumber = mo.groups()

print("Area code: " + areaCode)
print("Main: " + mainNumber)

paper_clip = re.compile(r'.*')
text = str(pyperclip.paste())

matches = []

for groups in paper_clip.findall(text):
    print(groups)
    if groups != '':
        matches.append(groups)

print(matches)

# value = input("Would you like to create a directory? ")
# if value == "yes":
#   name = input("Where would you like the directory to be made (inlude name): ")
#   os.system('mkdir ' + name)
# else:
#   print("darn")

# class Rectangle:
#     def __init__(self, length, width):
#         self.length = length
#         self.width = width

#     def area(self):
#         return self.length * self.width

#     def perimeter(self):
#         return 2 * self.length + 2 * self.width

# class Square(Rectangle):
#     def __init__(self, length, **kwargs):
#         super().__init__(length, length)

#     def area(self):
#         return super().area() * 20

# class Cube(Square): # uses the __init__ of superclass

#     #calls the area funcition from rectangle, not Square
#     def surface_area(self):
#         face_area = super(Square, self).area() 
#         return face_area * 6

#     def volume(self):
#         face_area = super().area()
#         return face_area * self.length

# asuna = Square(25)
# asunaCubed = Cube(25)
# print(asuna.area())
# print(asunaCubed.surface_area())



