"proj09.py is a program that checks for the coocurrance of words throughout the file and prints the line numbers."

_Author_ = "Nathan Dohm"
_email_ = "dohmnath@msu.edu"
_version_ = "3.5.2"


import string
from collections import defaultdict

def open_file():
	'''opens the user specified file if it exists; otherwise, it prompts for another file'''
	file = input("Enter a file name: ")
	while True:
		try:
			fp = open(file, "r")
			return fp
		except IOError:
			file = input("\nError -- Enter a file name: ")

def read_data(fp):
	'''finds the string (without puntucation), converts it to lowercase, and then creates a dictionary, in which the values (locations of what line the 
	word/words are in) are placed into sets'''
	count = 0
	Data_dict = defaultdict(set)
	with fp as file:
		for i, line in enumerate(file): #used to find the line number
			if i == count:
				i = line.strip().split()
				for w in i:
					w = w.lower()
					w = w.strip(string.punctuation).replace("'", "").replace("-", "")
					if w.isalpha() and len(w) > 1:
						if w in Data_dict:
							Data_dict[w].add(str(count+1))
						else:
							Data_dict[w].add(str(count+1))
			count += 1
		return dict(Data_dict)

def find_cooccurance(D, inp_str):
	'''prints out the lines where the word occurs. If the user inputs multiple words, the program checks for the lines where both of the
	the user specified words are located'''
	cooccurance = []
	inp_str = inp_str.strip(string.punctuation).replace("'", "").replace("-", "")
	inp_str = inp_str.split()
	try:
		if len(inp_str) == 1: #returns dictionary of a single word (with line number)
			inp_str = "".join(inp_str)
			D = D[inp_str]
			D = list(map(int, D))
			D = sorted(D, key=int)
			return D
		else:
			for i in inp_str: #returns multiple words and their line numbers
				inp_str = "".join(i)
				F = D[inp_str]
				F = list(map(int, F))
				F = sorted(F)
				cooccurance.append(set(sorted(F)))
			lines = set.intersection(*cooccurance)
			lines = list(sorted(lines))
			return lines
	except KeyError:
		return None

def main():
	'''main function'''
	fp = open_file()
	D = read_data(fp)
	inp_str = input("\nEnter space seperated words: ")
	while "q" not in inp_str.lower():
		try:
			inp_str = inp_str.lower()
			print("The co-occurance for: " + (', '.join('{}'.format(k) for k in inp_str.split()))) #inputs commas after each line number where the word(s) occur
			lines = find_cooccurance(D, inp_str)
			if find_cooccurance(D, inp_str) != None:
				print("Lines: " + ", ".join(str(a) for a in lines))
			else:
				print("Lines: None.")
		except TypeError: #since intersection in line 61 needs an argument and "" is not an argument, this prints an error and prompts for new imput
			print("Lines: None.")
		inp_str = input("\nEnter space seperated words: ")
	else:
		quit()

if __name__ == '__main__':
	main()

#Questions
#6
#1
#1
#6
#1