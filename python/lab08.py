def counter(file, num):
	Benford =["(30.1%)", "(17.6%)", "(12.5%)", "(9.7%)", "(7.9%)", "(6.7%)", "(5.8%)", "(4.1%)", "(4.6%)"]
	file_open = open(file, "r")
	total = 0
	count = 0
	benford_index = num - 1
	Benford = Benford[benford_index]
	
	for i in file_open:
		i = i.strip()
		i = i.split()
		i = i[0][0]
		i = int(i)
		if i == num:
			count += 1
		total +=1
		percent = count/total * 100
	print("{:>5}".format(num) + ":", "{:>5.1f}".format(percent) + "%", "{:>1}".format(Benford))

def main():
	file = input("Name of file: ")
	print("Digit Percent Benford")
	num = 1
	for i in range(1, 10):
		counter(file, num)
		num +=1

main()
