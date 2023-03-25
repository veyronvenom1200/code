maximum = 10e-6
minimum = 10e6

def BMI():
	maximum = 10e-6
	minimum = 10e6
	file = open("data.txt", "r")
	file.readline()
	BMI_avg = 0
	count = 0
	print("\nName", "{:>13}".format("Height"), "{:>11}".format("Weight"), "{:>8}".format("BMI"))
	for i in file:
		words = i.split()
		words = words[1:2]
		height = "\n".join(words)
		height = float(height)
		words = i.split()
		words = words[2:]
		weight = "\n".join(words)
		weight = float(weight)
		BMI = weight/height**2
		count += 1
		if BMI > maximum:
			maximum = BMI
		if BMI < minimum:
			minimum = BMI
		i = i.strip()
		i = i + "{:>12.2f}".format(BMI)
		print(i)
		BMI_avg += BMI
	
	maximum = ("{:.2f}".format(maximum))
	minimum = ("{:.2f}".format(minimum))
	
	return (BMI_avg/count, maximum, minimum)

def height():
	maximum = 10e-6
	minimum = 10e6
	file = open("data.txt", "r")
	file.readline()
	height = 0
	count = 0
	for i in file:
		words = i.split()
		words = words[1:2]
		l = "\n".join(words)
		l = float(l)
		height += l
		count += 1
		if l > maximum:
			maximum = l
		if l < minimum:
			minimum = l

	return (height/count, maximum, minimum)

def weight():
	maximum = 10e-6
	minimum = 10e6
	file = open("data.txt", "r")
	file.readline()
	weight = 0
	count = 0
	for i in file:
		words = i.split()
		words = words[2:]
		list_l = "\n".join(words)
		list_l = float(list_l)
		weight += list_l
		count += 1
		if list_l > maximum:
			maximum = list_l
		if list_l < minimum:
			minimum = list_l

	return (weight/count, maximum, minimum)

def main_function():
	file = open("data.txt", "r")
	a, b, c = height()
	d, e, f = weight()
	g, h, i = BMI()
	print("\nAverage ", "{:>7.2f}".format(a), "{:>12.2f}".format(d), "{:>11.2f}".format(g))
	print("Max ", "{:>11}".format(b), "{:>12}".format(e), "{:>11}".format(h))
	print("Min ", "{:>11}".format(c), "{:>11}".format(f), "{:>12}".format(i))

main_function()
