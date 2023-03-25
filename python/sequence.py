number = input("Number sequence: ")
Bool = False

while Bool is False:
    lst = []
    num = 0
    while number.isalpha() or int(number) < 0:
        print("Input must be a whole number. Try again.")
        number = input("Number sequence: ")
    split = int(input("Split evenly by: "))
    if len(number) % split == 0:
        Bool = True
        index = int(len(number) / split)
        for i in range(0, len(number), split):
            lst.append(number[i: (split + i)])
        print(', '.join(lst))
        if len(lst) == 0:
            print("Sequence is increasing")
        for x in lst:
            if int(x) > num:
                num = int(x)
                if num == int(lst[-1]):
                    print("Sequence is increasing")
            else:
                print("Sequence is not increasing")
                break

    else:
        print(number, "must be evenly divisible by", split)
        print("Try again")
        Bool = False
