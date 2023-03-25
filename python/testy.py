# total = 0

# def sum_of_list(lst, total = 0):
# 	if len(lst) == 1:
# 		# total = total + lst[0]
# 		# print(total)
# 		return total

# 	else:
# 		mid =  len(lst) // 2
# 		lower = lst[:mid]
# 		upper = lst[mid:]

# 		sum_of_list(lower, total)
# 		sum_of_list(upper, total)

# 	return total

# l = [1, 2, 3, 4, 5, 6]

# total = 0

# print(sum_of_list(l, total))

import numpy as np
import collections

a = np.array([1, 2, 3, 4, 5, 6, 6, 7, 7 ,8, 9, 10])

# rank = list('JKQA')

for _ in a:
	print(_)

five_up = (a >= 5)

test_dict = {num: a[five_up][num] for num in range(0, 8)}

print(test_dict)

print(a[five_up])

arr = np.arange(6)
print(arr)
def list_sum(num_List):
	print(num_List)
	if len(num_List) == 1:
		return num_List[0]
	else:
		return num_List[0] + list_sum(num_List[1:])
        
print(list_sum([2, 4, 5, 6, 7]))
print('spades diamonds clubs hearts'.split())
# print(rank)

Card = collections.namedtuple('Card', ['rank', 'suit'])

class FrenchDeck:
	ranks = [str(n) for n in range(2, 11)] + list('JQKA')
	suits = 'spades diamonds clubs hearts'.split()

	def __init__(self):
		self._cards = [Card(rank, suit) for suit in self.suits
										for rank in self.ranks]

	def __len__(self):
		return len(self._cards)

	def __getitem__(self, position):
		return self._cards[position]

beer_card = Card('7', 'diamonds')
print(beer_card)

deck = FrenchDeck()

print(len(deck))

