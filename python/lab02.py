"""lab02 is a program that takes all positive integers entered by the user and
adds the even numbers together, and it adds the odd numbers together. The program
also counts (and displays) the number of odd numbers entered, and the number of
even numbers entered. When negative values are entered the program ignores them
and prints out that the number is negative, and then continues to prompt the user
for more values. 0 terminates the program."""

_Author_ = "Nathan Dohm"
_version_ = "3.5.2"
_email_ = "dohmnath@msu.edu"

# list of all the variables used in the program
integer_int = 1
odd_count = 0
even_count = 0
even_sum = 0
odd_sum = 0
positive_int = 0

while (integer_int > 0 or integer_int < 0):
    integer_str = input("Input an interger (0 terminates): ")
    integer_int = int(integer_str)


    if (integer_int < 0):
        print(integer_int, " is negative.")
        continue

# count the number of positive intergers
    if (integer_int > 0):
        positive_int
        positive_int += 1

# when 0 is entered, the program subtracts 1 off of even_count since 0
# terminates the program
    if (integer_int == 0):
        even_count = even_count - 1

# count the number of even intergers entered
    if (integer_int % 2 == 0):
        even_count
        even_count += 1
        even_sum += integer_int

# count the number of odd intergers entered
    elif (integer_int % 2 == 1):
        odd_count
        odd_count = odd_count + 1
        odd_sum = odd_sum + integer_int

    else:
        break

#print all the values that were found (odd_sum, even_sum, odd_count, even_count,
#and positive_int)
print("\nSum of odd numbers: ", odd_sum)
print("Sum of even numbers: ", even_sum)
print("Count of odd numbers: ", odd_count)
print("Count of even numbers: ", even_count)
print("Total positive int count: ", positive_int)
