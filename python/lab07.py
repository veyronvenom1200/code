def organize(file):
    scores = open(file, "r")
    listed = []
    for i in scores:
        i = i.split()
        listed += [i]
    listed = tuple(listed)
    listed = sorted(listed)
    return listed

def Exam1(file, listed):
    for i in listed:
        exam = i
        exam = exam[2]
        exam = " ".join(exam)
        return exam

def Class_Average_Exam1(file, listed):
    class_average = 0
    count = 0
    for i in listed:
        average = i
        average = int(average[2])
        class_average += average
        count += 1
    class_average = class_average / count
    return class_average

def Class_Average_Exam2(file, listed):
    class_average = 0
    count = 0
    for i in listed:
        average = i
        average = int(average[3])
        class_average += average
        count += 1
    class_average = class_average / count
    return class_average

def main():
    file = input("File name (with extension): ")
    scores = open(file, "r")
    listed = organize(file)
    a = Class_Average_Exam1(file, listed)
    b = Class_Average_Exam2(file, listed)
    print("Student Name", "{:>12}".format("Exam 1"), "{:>12}".format("Exam 2"), "{:>12}".format("Average"))
    for i in listed:
            names = i[:2]
            exam1 = i[2]
            exam2 = i[3]
            average = (int(i[2]) + int(i[3])) / 2
            average = str(average)
            names = " ".join(names)
            name_len = len(names)
            name_len = 19 - name_len
            if exam1 == 100:
                name_len -= 1
            exam1 = "".join(exam1)
            exam1_len = len(exam1)
            exam1_len = 13 - exam1_len
            exam2 = "".join(exam2)
            exam2_len = len(exam2)
            exam2_len = 12 - exam2_len
            print(names + (" " * name_len) + exam1 + (" " * exam1_len) + exam2 + (" " * exam2_len) + average)
    print("\nClass Averages", "{:>8}".format(a), "{:>12}".format(b))

main()
