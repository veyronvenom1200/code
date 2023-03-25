import random

lst = []
for i in range(0, 20):
    lst.append(random.randint(0, 10))

print(lst)

class Pizza:
    def __init__(self, ingredients):
        self.ingredients = ingredients

    def __repr__(self):
        return f'Pizza({self.ingredients!r})'

    @classmethod
    def margherita(cls):
        return cls(['mozzarella', 'tomatoes'])

    @classmethod
    def prosciutto(cls):
        return cls(['mozzarella', 'tomatoes', 'ham'])

class Computer:
    def __init__(self, manufacturer, operating_system):
        self.manufacturer = manufacturer
        self.operating_system = operating_system

    @classmethod
    def apple(cls, manufacturer, operating_system):
        return cls('apple', 'macos')

    def __str__(self):
        return f'Successful creation of %s' % self.manufacturer


apple = Computer.apple('apple', 'macos')
apple.manufacturer = 'microsoft'
print(apple)

print(Pizza.prosciutto())

