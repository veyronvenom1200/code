import csv

LIST = ['State','Heart Disease Death Rate (2007)','Stroke Death Rate (2007)','HIV Diagnosis Rate (2009)','CLABSI-SIR (2010)','Motor Vehicle Death Rate (2009)','Opioid Analgesics Deaths (2007)','Teen Birth Rate (2009)','Diagnosed High Cholesterol (2009)','Diagnosed Hypertension (2009)','Medicated Hypertension(2009)','Adult Smoking (2010)','Youth Smoking (2009)','Adult Obesity (2010)','Youth Obesity (2009)','Adult Seat Belt Use (2009)','Youth Seat Belt Use (2009)','Adult Binge Drinking (2010)','Youth Binge Drinking (2009)','Colorectal Cancer Screening (2010)','Without Health Care Coverage (2010)']


def csv_file(fp):
    count = 0
    state_list = []
    csv = open(fp, 'r')
    for a in csv:
        a = a.replace(' ', '_')
        a = a.replace(',', ' ')
        state_list.append([])
        for states in a.split():
            state_list[count].append(states)
        count += 1

    state_list = state_list[(len(state_list) - 51): len(state_list)]

    return state_list


def high(state_list, a):
    lst = []
    for i in range(len(state_list)):
        try:
            lst.append(float(state_list[i][a]))
        except ValueError:
            index = state_list[i][a].strip('%')
            lst.append(float(index))
    return max(lst), state_list[lst.index(max(lst))][0]


def low(state_list, a):
    lst = []
    for i in range(len(state_list)):
        try:
            lst.append(float(state_list[i][a]))
        except ValueError:
            index = state_list[i][a].strip('%')
            lst.append(float(index))
    return min(lst), state_list[lst.index(min(lst))][0]


#fp = input("Name of file: ")
state_list = csv_file('cdc.csv')

print('{:31s}'.format("Indicator") + '{:35s}'.format(":Min") + "Max")
print('-' * 95)
for a in [1, 5, 7, 11, 13]:
    maximum, state = high(state_list, a)
    state = state.replace('_', ' ')
    minimum, state_name = low(state_list, a)
    state_name = state_name.replace('_', ' ')
    print('{:31s}'.format(LIST[a]) + ':' + '{:24s}'.format(state_name) + '{:5}'.format(minimum) + '     ' + '{:24s}'.format(state) + '{:5}'.format(maximum))
