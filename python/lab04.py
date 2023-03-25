_Author_ = "Nathan Dohm"

_version_ = "3.5.2"

_email_ = "dohmnath@msu.edu"

def sum_of_squares(initial, terms):
    initial_int = int(initial)
    terms_int = int(terms)
    sum_int = 0
    for i in range(terms_int):
        squares = initial_int ** 2
        sum_int += squares
        initial_int += 1
    print(sum_int)

def sum_of_cubes(initial, terms):
    initial_int = int(initial)
    terms_int = int(terms)
    sum_int = 0
    for i in range(terms_int):
        cubes = initial_int ** 3
        sum_int += cubes
        initial_int += 1
    print(sum_int)

def power(initial, terms, exponent):
    initial_int = int(initial)
    terms_int = int(terms)
    exponent_int = int(exponent)
    sum_int = 0
    for i in range(terms_int):
        number = initial_int ** exponent_int
        sum_int += number
        initial_int += 1
    print(sum_int)

def get_start_input():
    return input("For sum of squares, type 'squares'. For sum of cubes, type 'cubes'. "
              "\nIf you would like to raise a number to something other than 'squares' or 'cubes', type 'power'. "
              "\nIf you would like to exit, type 'exit':")

def main_function():
    while True:
        start = get_start_input()
        if start.lower() == "squares":
            initial = input("What is the initial constant for the sum of the squares: ")
            terms = input("Number of terms: ")
            sum_of_squares(initial, terms)

        elif start.lower() == "cubes":
            initial = input("What is the initial constant for the the sum of the cubes: ")
            terms = input("Number of terms: ")
            sum_of_cubes(initial, terms)

        elif start.lower() == "power":
            initial = input("What is the initial constant for the the sum: ")
            terms = input("Number of terms: ")
            exponent = input("Raise to power:")
            power(initial, terms, exponent)

        elif start.lower() == "exit":
            print("Program halted normally.")
            break

        else:
            print("***Invalid Choice***")

main_function()
